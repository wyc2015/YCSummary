//
//  YCStudent+CoreDataProperties.m
//  YCSummary
//
//  Created by wuyongchao on 2018/11/13.
//  Copyright © 2018年 YC科技有限公司. All rights reserved.
//
//

#import "YCStudent+CoreDataProperties.h"

@implementation YCStudent (CoreDataProperties)

+ (NSFetchRequest<YCStudent *> *)fetchRequest {
	return [NSFetchRequest fetchRequestWithEntityName:@"YCStudent"];
}

@dynamic age;
@dynamic name;
@dynamic teacher;

@end
