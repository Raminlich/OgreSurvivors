#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include <iostream>

using namespace Ogre;
using namespace OgreBites;
using namespace RTShader;

int main()
{
    ApplicationContext ctx("Ogre-Survivors");
    ctx.initApp();

    Root* root = ctx.getRoot();
    SceneManager* sceneManager = root->createSceneManager();

    ShaderGenerator* shadergen = ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(sceneManager);

    sceneManager->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    Light* light = sceneManager->createLight("MainLight");
    SceneNode* lightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    lightNode->setPosition(20, 80, 50);

    
    Camera* mainCamera = sceneManager->createCamera("MainCamera");
    mainCamera->setNearClipDistance(5);
    mainCamera->setAutoAspectRatio(true);
    SceneNode* mainCameraNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    mainCameraNode->attachObject(mainCamera);
    mainCameraNode->setPosition(0, 0, 140);


    Entity* ogreHeadMesh = sceneManager->createEntity("ogrehead.mesh");
    SceneNode* ogreMeshNode = sceneManager->getRootSceneNode()->createChildSceneNode();
    ogreMeshNode->attachObject(ogreHeadMesh);

    ctx.getRenderWindow()->addViewport(mainCamera);


    return 0;
}

//! [fullsource]