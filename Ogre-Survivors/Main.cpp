#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "GameObject.h"
#include "CameraController.h"
#include "InputManager.h"
#include "InputHandler.h"
#include <vector>

using namespace Ogre;
using namespace OgreBites;
using namespace RTShader;

class BaseWindow : public ApplicationContext
{
private:
public:
    BaseWindow();
    virtual ~BaseWindow() {}
    void setup() override;
    SceneManager *sceneManager;
};

BaseWindow::BaseWindow() : ApplicationContext("Ogre")
{
}

void CreateLight(Ogre::SceneManager* sceneManager, Ogre::Vector3 dir,String name) 
{
    Light* directionalLight = sceneManager->createLight("DirectionalLight"+name);
    directionalLight->setType(Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(ColourValue(1, 1, 1));
    directionalLight->setSpecularColour(ColourValue(1, 1, 1));
    SceneNode* dirLightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    dirLightNode->setPosition(Ogre::Vector3(0,0,0));
    dirLightNode->setDirection(Vector3(dir));
    dirLightNode->attachObject(directionalLight);
}

void BaseWindow::setup()
{
    ApplicationContext::setup();
    Root *root = getRoot();
    sceneManager = root->createSceneManager();
    ShaderGenerator *shadergen = ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(sceneManager);

    Camera *mainCamera = sceneManager->createCamera("MainCamera");
    mainCamera->setNearClipDistance(5);
    mainCamera->setFarClipDistance(0);
    mainCamera->setAutoAspectRatio(true);
    SceneNode *mainCameraNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    mainCameraNode->attachObject(mainCamera);
    mainCameraNode->setPosition(0, 0 , 300);
    mainCameraNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
    getRenderWindow()->addViewport(mainCamera);
    sceneManager->setAmbientLight(ColourValue(0, 0, 0));
    sceneManager->setShadowTechnique(ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE);
  
    //kossher start
    CreateLight(sceneManager,Ogre::Vector3(0,0,0),"1");
    CreateLight(sceneManager, Ogre::Vector3(1, 1, 1),"2");
    CreateLight(sceneManager, Ogre::Vector3(1, 1, -1),"3");
    CreateLight(sceneManager, Ogre::Vector3(1, -1, 1),"4");
    CreateLight(sceneManager, Ogre::Vector3(-1, -1, -1),"5");
    CreateLight(sceneManager, Ogre::Vector3(-1, -1, 1),"6");
    CreateLight(sceneManager, Ogre::Vector3(-1, 1, 1),"7");
    CreateLight(sceneManager, Ogre::Vector3(-1,1,-1),"8");
    //kossher end

    GameObject *ogreHead = new GameObject(sceneManager, "ogrehead");
    Ogre::SceneNode *attachmentNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    root->addFrameListener(ogreHead);

    InputManager* inputManager = new InputManager();
    root->addFrameListener(inputManager);

    std::vector<Input*> inputs = inputManager->GetInputs();
    for (auto input : inputs) 
    {
        addInputListener(input);
    }

    CameraController* cameraController = new CameraController(mainCamera, mainCameraNode, inputManager);
    root->addFrameListener(cameraController);
}

int main()
{
    BaseWindow baseWindow;
    baseWindow.initApp();
    baseWindow.getRoot()->startRendering();
    baseWindow.closeApp();
    return 0;
}
