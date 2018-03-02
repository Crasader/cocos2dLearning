//
//  KeyMobileScene.h
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#include "cocos2d.h"

class KeyMobileScene: public cocos2d::Layer, public cocos2d::TextFieldDelegate {
public:
    
    virtual ~KeyMobileScene();
    virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender) override;
    
    virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *sender) override;
    
    virtual bool onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen) override;
    
    virtual bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *sender, const char *delText, size_t nLen)
    override;
    
    virtual bool onVisit(cocos2d::TextFieldTTF *sender, cocos2d::Renderer *renderer,
                         cocos2d::Mat4 const &transform, uint32_t flags) override;
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(KeyMobileScene);
};

