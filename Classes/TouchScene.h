//
//  TouchScene.h
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#ifndef TouchScene_h
#define TouchScene_h

#include "cocos2d.h"

class TouchScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TouchScene);

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
private:
    cocos2d::Label* labelTouchInfo;
};

#endif /* TouchScene_h */
