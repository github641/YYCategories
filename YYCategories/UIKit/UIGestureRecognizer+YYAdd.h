//
//  UIGestureRecognizer+YYAdd.h
//  YYCategories <https://github.com/ibireme/YYCategories>
//
//  Created by ibireme on 13/10/13.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//
/* lzy注170607：
 与非常多的yy的其他category相似，加入blcok回调，会使用的是associated。
 基本流程是，
 1、在addActionBlock的时候，会创建一个targetObject对象，并且targetObject对象associated了self。
 这个对象，用来管理（持有、调用）block。
 2、创建数组或者字典，它associated了self，管理所有的actionBlock。addActionBlock时，添加到它中，并提供removeAllActionBlocks方法，移除所有添加的actionBlock。
 
 self会把target设置为targetObject
 self会把action设置为targetObject类中的invoke方法。
 当self接收到动作触发的时候，会去targetObject中，触发invoke方法。
 invoke方法中，将触发block。
 
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides extensions for `UIGestureRecognizer`.
 */
@interface UIGestureRecognizer (YYAdd)

/**
 Initializes an allocated gesture-recognizer object with a action block.
 
 @param block  An action block that to handle the gesture recognized by the 
               receiver. nil is invalid. It is retained by the gesture.
 
 @return An initialized instance of a concrete UIGestureRecognizer subclass or 
         nil if an error occurred in the attempt to initialize the object.
 */
- (instancetype)initWithActionBlock:(void (^)(id sender))block;

/**
 Adds an action block to a gesture-recognizer object. It is retained by the 
 gesture.
 
 @param block A block invoked by the action message. nil is not a valid value.
 */
- (void)addActionBlock:(void (^)(id sender))block;

/**
 Remove all action blocks.
 */
- (void)removeAllActionBlocks;

@end

NS_ASSUME_NONNULL_END
