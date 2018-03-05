//
//  ActionScene.h
//  MyCppGame
//
//  Created by cowell on 3/5/18.
//

#include "cocos2d.h"

class ActionScene: public cocos2d::Layer {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(ActionScene);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
private:
    cocos2d::Sprite* car;
};
