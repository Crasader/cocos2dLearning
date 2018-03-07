
#include "TouchScene.h"

USING_NS_CC;

Scene* TouchScene::createScene() {
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool TouchScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto colorLayer = LayerColor::create(Color4B::YELLOW, this->getBoundingBox().getMaxX(), this->getBoundingBox().getMaxY());
    this->addChild(colorLayer);
    this->setIgnoreAnchorPointForPosition(false);
    labelTouchInfo = Label::createWithSystemFont("Touch here to begin", "Arial", 12);
    labelTouchInfo->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height/2));
    
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    this->addChild(labelTouchInfo);
    return true;
}

bool TouchScene::onTouchBegan(Touch *touch, Event* event)
{
    labelTouchInfo->setPosition(touch->getLocation());
    labelTouchInfo->setString("you touch here");
    return true;
}

void TouchScene::onTouchEnded(Touch *touch, Event* event)
{
    cocos2d::log("touch end");
}

void TouchScene::onTouchMoved(Touch *touch, Event *event)
{
    labelTouchInfo->setPosition(touch->getLocation());
    labelTouchInfo->setString("you touch here");
    cocos2d::log("touch moved");
}

void TouchScene::onTouchCancelled(Touch *touch, Event *event)
{
    cocos2d::log("touch cancel");
}
