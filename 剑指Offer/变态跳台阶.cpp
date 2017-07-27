class Solution {
public:
    int jumpFloorII(int number) {
		// 一共number个台阶，要么踩，要么不踩，当然最后一格是一定要踩的，因此2^(n-1)
        return 1<<--number;//将1左移(number-1)位
    }
};