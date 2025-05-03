//
//  Tweak.m
//  PatchCode_NoJB
//
//  Created by IosBX on 2025/5/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "static-inline.h"

static void __attribute__((constructor)) _init_() {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2* NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //路径是.app中主程序的相对路径 例如QQ WeChat Smoba Frameworks/UnityFramework.framework/UnityFramework
        ActiveCodePatch("IpaDownloadTool",0x12345678, "C0035FD6"); //修改
        DeactiveCodePatch("IpaDownloadTool",0x12345678, "C0035FD6"); //恢复
    });
}
