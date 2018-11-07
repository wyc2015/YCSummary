//
//  YCArraySort.h
//  YCSummary
//
//  Created by wuyongchao on 2018/11/7.
//  Copyright © 2018年 YC科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YCArraySort : NSObject
/**
 * desc: 冒泡排序
 *    1. 进行两次遍历，第一个for是从 0 - arr.length, 第二次是从0到 arr.length-i - 1;
 *    2. 每一趟之后最后一个是最大值；
 *  原理：这种算法会重复的比较数组中相邻的两个元素，如果一个元素比另一个元素大（小），那么就交换这两个元素的位置。重复这一比较直至最后一个元素。每一趟比较都能找出未排序元素中最大或者最小的那个数字。这就如同水泡从水底逐个飘到水面一样。冒泡排序是一种时间复杂度较高，效率较低的排序方法。

 * 时间复杂度: 最好情况o(n), 最差o(n^2), 平均o(n^2)，优化后可能达到O(n)，但会增加空间复杂度
 *
 * 空间复杂度: 0(1)
 */
+ (NSMutableArray *)bubbleSort:(NSArray *)array;
/**
 * desc: 选择排序
 *    1. 分为两趟，第一趟从0-arr.length-1, 第二趟从i + 1到arr.length
 *    2. 每趟的结果是最小值在最左边
    原理：从第一个元素开始，依次查找对比，找到最小的元素与第一个元素交换，再从第二个元素开始找后面元素的最小值与第二个元素交换，以此类推，直到整个数组有序。
 *
 * 时间复杂度：最好情况o(n^2), 最差o(n^2), 平均o(n^2)
 * 空间复杂度：o(1)
 */
+ (NSMutableArray *)selectSort:(NSArray *)array;
/**
 * desc: 插入排序
 *  1. 从第一个元素开始，认为该元素已经是排好序的。
 　　2. 取下一个元素，在已经排好序的元素序列中从后向前扫描。
 　　3. 如果已经排好序的序列中元素大于新元素，则将该元素往右移动一个位置。
 　　4. 重复步骤3，直到已排好序的元素小于或等于新元素。
 　　5. 在当前位置插入新元素。
 　　6. 重复步骤2。
 *
 * 时间复杂度：最好情况o(n), 最差o(n^2), 平均o(n^2)
 * 空间复杂度：o(1)
  优势：对于有序数组或部分有序数组，此排序方法是十分高效的，很适合小规模的数组，很多高级的排序算法都会利用到插入排序。
  劣势：若果最少的元素都在最后部分的位置，那么该排序方法就会变得非常费劲了，最后的元素都要比较改元素位置减一次。
 */
+ (NSMutableArray *)insertSort:(NSArray *)array;
/**
 * desc: 快速排序
 *    1. 找到中间值，将其分为两个数组，不包括中间的值，左边的小于等于中间值，右边大于中间值；
 *    2. 递归调用快排，返回结果为左边数组连接中间值和右边数组
 *  分解：
 　　　　A[p..r]被划分为俩个（可能空）的子数组A[p ..q-1]和A[q+1 ..r]，使得
 　　　　A[p ..q-1] <= A[q] <= A[q+1 ..r]
 　　　　2.解决：通过递归调用快速排序，对子数组A[p ..q-1]和A[q+1 ..r]排序。
 　　　　3.合并。
 * 时间复杂度：最好情况o(nlogn), 最差o(n^2), 平均o(nlogn)
 *
 * 空间复杂度：o(logn)
 */
+ (NSMutableArray *)quickSort:(NSArray *)array;
/**
 * desc: 归并排序https://www.jianshu.com/p/8fce5bfb0013
               https://www.jianshu.com/p/04d9480a0633
 *    1. 取中间值为哨兵，将数组分为两个数组，左数组都小于等于哨兵，右边都大于哨兵
 *    2. 进行递归合并，合并函数为：定义一个数组，比较两数组中的第一个元素，将小的插入到result中，直到一个数组length为0
 *    3. 检查两数组是否长度有不为0的，如果不为0，将其接在result上面
 *  所谓归并，是指将若干个已排好序的子序列合并成一个有序的序列。归并是一种常见运算，其方法是：比较各子序列的第一个记录的键值，最小的一个就是排序后序列的第一个记录的键值。取出这个记录，继续比较各子序列现在的第一个记录的键值，便可找出排序后的第二记录。如此继续下去，最终可以得到排序结果。因此，归并排序的基础是归并。
 * 时间复杂度：o(nlongn)
 *
 * 空间复杂度：0(n)
 */
+ (NSMutableArray *)mergeSort:(NSArray *)array;
/**
 * desc: 堆排序https://www.jianshu.com/p/fe271bc3e544
 *原理：
  1.从下往上，从右往左的顺序查找每个非叶子结点，对比子结点，与最大结点交换位置，交换的新位置再与其子结点比较、移动，遍历后最终找到最大值，形成一个大顶堆（小顶堆也行）。
  2.把堆顶和最后的元素交换位置，排除最后的位置，重复1步骤，找到遍历后的最大值，放到倒数第二的位置，依次直到结束。
 堆 是具有下列性质的完全二叉树：每个节点的值都大于或等于其左右孩子节点的值，称为大顶堆；或者每个节点的值都小于或等于其左右孩子结点的值称为小顶堆。
 * 时间复杂度：最好情况o(nlongn), 最差o(nlongn), 平均o(nlongn)
 * 空间复杂度：0(n)
 堆排序是一种不稳定的排序方法
 */
+ (NSMutableArray *)heapSort:(NSMutableArray *)ascendingArr;
/*希尔排序 https://www.jianshu.com/p/b6d9fb791443
 思路：希尔排序是1959 年由D.L.Shell 提出来的，相对直接排序有较大的改进。希尔排序又叫缩小增量排序。
 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
 时间复杂度：最好情况0(n), 最差O(n^2), 平均0(n^1.3)
  * 空间复杂度：0(n)
 */

+(NSMutableArray *)shellArray:(NSMutableArray *)array;
@end

NS_ASSUME_NONNULL_END