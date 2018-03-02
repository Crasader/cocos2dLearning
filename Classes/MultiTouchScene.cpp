//
//  MultiTouchScene.cpp
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#include "MultiTouchScene.h"
USING_NS_CC;

Scene* MultiTouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MultiTouchScene::create();
    scene->addChild(layer);
    return scene;
}

bool MultiTouchScene::init()
{
    if ( !Layer::init())
    {
        return false;
    }
    
    for (int i = 0; i < MAX_TOUCHES; i++) {
        labelTouchLocation[i] = Label::createWithSystemFont("", "Arial", 25);
        labelTouchLocation[i]->setVisible(false);
        this->addChild(labelTouchLocation[i]);
    }
    
    auto eventListener = EventListenerTouchAllAtOnce::create();
    
    eventListener->onTouchesBegan = [=](const std::vector<Touch*>&touches, Event* event) {
        std::for_each(labelTouchLocation, labelTouchLocation+MAX_TOUCHES, [](Label* touchLabel){
            touchLabel->setVisible(false);
        });
        
        for (int i = 0; i < touches.size(); i++) {
            labelTouchLocation[i]->setPosition(touches[i]->getLocation());
            labelTouchLocation[i]->setVisible(true);
            labelTouchLocation[i]->setString("Touches");
        }
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    
    return true;
}


