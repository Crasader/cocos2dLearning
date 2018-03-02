//
//  KeyMobileScene.cpp
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#include "KeyMobileScene.h"
USING_NS_CC;

Scene* KeyMobileScene::createScene()
{
    auto scene = Scene::create();
    auto Layer = KeyMobileScene::create();
    
    scene->addChild(Layer);
    
    return scene;
}


bool KeyMobileScene::init()
{
    if ( !Layer::init() ) {
        return false;
    }
    
    // Create a text field
    TextFieldTTF* textField = cocos2d::TextFieldTTF::textFieldWithPlaceHolder("Click here to type",
                                                                              cocos2d::Size(100,40),TextHAlignment::LEFT , "Arial", 12.0);
    textField->setPosition(this->getBoundingBox().getMidX(),
                           this->getBoundingBox().getMaxY() - 20);
    textField->setColorSpaceHolder(Color3B::GREEN);
    textField->setDelegate(this);
    
    this->addChild(textField);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [](cocos2d::Touch* touch, cocos2d::Event * event) -> bool {
        try {
            // Show the on screen keyboard
            auto textField = dynamic_cast<TextFieldTTF *>(event->getCurrentTarget());
            textField->attachWithIME();
            return true;
        }
        catch(std::bad_cast & err){
            return true;
        }
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, textField);
    
    return true;
}

KeyMobileScene::~KeyMobileScene()
{
    
}

bool KeyMobileScene::onTextFieldAttachWithIME(TextFieldTTF *sender) {
    return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool KeyMobileScene::onTextFieldDetachWithIME(TextFieldTTF *sender)
{
    return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}

bool KeyMobileScene::onTextFieldInsertText(TextFieldTTF *sender, const char *text, size_t nLen)
{
    return TextFieldDelegate::onTextFieldInsertText(sender, text, nLen);
}

bool KeyMobileScene::onTextFieldDeleteBackward(TextFieldTTF *sender, const char *text, size_t nLen)
{
    return TextFieldDelegate::onTextFieldDeleteBackward(sender, text, nLen);
}

bool KeyMobileScene::onVisit(TextFieldTTF *sender, Renderer *render, const Mat4 &tranform, uint32_t flag)
{
    return TextFieldDelegate::onVisit(sender, render, tranform, flag);
}

