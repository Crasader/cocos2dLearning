//
//  ActionScene.cpp
//  MyCppGame
//
//  Created by cowell on 3/5/18.
//

#include "ActionScene.h"
USING_NS_CC;

Scene* ActionScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ActionScene::create();
    scene->addChild(layer);
    return scene;
}

bool ActionScene::init()
{
    if ( !Layer::init() ) {
        return false;
    }
    
    car = Sprite::create("veyron.png");
    car->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
//    car->setPosition(Vec2(0, 0));
    this->addChild(car);
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = CC_CALLBACK_2(ActionScene::onTouchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true; 
}

bool ActionScene::onTouchBegan(Touch* touch, Event* event)
{
    auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0,0));
    car->runAction(action);
    return true;
}


