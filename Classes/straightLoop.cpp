//
//  straightLoop.cpp
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#include "straightLoop.h"

USING_NS_CC;

Scene* straightLoop::createScene()
{
    auto scene = Scene::create();
    auto layer = straightLoop::create();
    scene->addChild(layer);
    return scene;
}

bool straightLoop::init()
{
    if ( !Layer::init() ) {
        return false;
    }
    
    car = Sprite::create("veyron.png");
    car->setScale(0.5, 0.5);
    car->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(car);
    this->scheduleUpdate();
    return true;
}

void straightLoop::update(float delta)
{
    auto position = car->getPosition();
    position.x -= 60*delta;
    if ( position.x < 0 - (car->getBoundingBox().size.width / 2) ) {
        position.x = this->getBoundingBox().getMaxX() + car->getBoundingBox().size.width/2;
    }
    car->setPosition(position);
}
