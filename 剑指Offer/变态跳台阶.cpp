class Solution {
public:
    int jumpFloorII(int number) {
		// һ��number��̨�ף�Ҫô�ȣ�Ҫô���ȣ���Ȼ���һ����һ��Ҫ�ȵģ����2^(n-1)
        return 1<<--number;//��1����(number-1)λ
    }
};