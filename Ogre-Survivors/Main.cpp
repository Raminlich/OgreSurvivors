#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "GameObject.h"

using namespace Ogre;
using namespace OgreBites;
using namespace RTShader;


class BaseWindow : public ApplicationContext
{
private:
public:
    BaseWindow();
    virtual ~BaseWindow() {}
    void setup();
    SceneManager* sceneManager;

};


BaseWindow::BaseWindow() : ApplicationContext("Ogre")
{
}

void BaseWindow::setup()
{
    ApplicationContext::setup();
    Root* root = getRoot();
    sceneManager = root->createSceneManager();
    ShaderGenerator* shadergen = ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(sceneManager);

    Camera* mainCamera = sceneManager->createCamera("MainCamera");
    mainCamera->setNearClipDistance(5);
    mainCamera->setFarClipDistance(0);
    mainCamera->setAutoAspectRatio(true);
    SceneNode* mainCameraNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    mainCameraNode->attachObject(mainCamera);
    mainCameraNode->setPosition(0, 0, 10);
    getRenderWindow()->addViewport(mainCamera);
    sceneManager->setAmbientLight(ColourValue(0, 0, 0));
    sceneManager->setShadowTechnique(ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE);
    Light* directionalLight = sceneManager->createLight("DirectionalLight");
    directionalLight->setType(Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(ColourValue::White);
    directionalLight->setSpecularColour(0, 0, 0);
    SceneNode* dirLightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    dirLightNode->setDirection(Vector3(0, 0, 0));
    dirLightNode->attachObject(directionalLight);
    //GameObject* redCube = new GameObject(sceneManager, "RedCube");
    Ogre::SceneNode* attachmentNode = sceneManager->getRootSceneNode()->createChildSceneNode();

    // Set the desired resource group first and then load the Scene
    attachmentNode->loadChildren("Sample.scene");

}

int main()
{
    BaseWindow baseWindow;
    baseWindow.initApp();
    baseWindow.getRoot()->startRendering();
    baseWindow.closeApp();
    return 0;
}
