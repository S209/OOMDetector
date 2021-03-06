//
//  QQLeakChecker.h
//
//  Created by rosenluo on 16/3/22.
//  Copyright © 2016年 tencent. All rights reserved.
//  version:1.0


#import <Foundation/Foundation.h>

typedef void (^QQLeakCheckCallback)(NSString *leakData,size_t leak_num);

@interface QQLeakChecker : NSObject

+(QQLeakChecker *)getInstance;

/*! @brief 开始记录内存分配堆栈
 *
 */
-(void)startStackLogging;

/*! @brief 停止记录内存分配堆栈
 *
 */
-(void)stopStackLogging;

- (BOOL)isStackLogging;


/*! @brief 设置记录堆栈的最大长度
 *
 * @param depth 堆栈最大长度，建议不要将该值设置过高，否则会占用过多内存,默认为10
 */
-(void)setMaxStackDepth:(size_t)depth;

/*! @brief 设置在堆栈中是否需要显示系统函数，建议打开
 *
 * @param isNeedSys YES表示需要系统方法堆栈
 */
-(void)setNeedSystemStack:(BOOL)isNeedSys;

/*! @brief 执行一次泄露检测，建议在主线程调用，该操作会挂起所有子线程进行泄露检测（该操作较耗时，平均耗时在1s以上，请限制调用频率）
 *
 * @param callback 泄露检测完毕后的回调，leakData为泄露堆栈数据，leak_num为泄露个数
 */
-(void)executeLeakCheck:(QQLeakCheckCallback)callback;

/*! @brief 获取当前记录的对象个数
 *
 */
-(size_t)getRecordObjNumber;

/*! @brief 获取当前记录的内存分配堆栈个数
 *
 */
-(size_t)getRecordStackNumber;

/*! @brief 获取QQLeak工具所占用的内存，单位字节
 *
 */
-(double)getOccupyMemory;

@end
