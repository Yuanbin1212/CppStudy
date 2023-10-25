// https://leetcode.cn/problems/combinations/

#include <vector>
#include <iostream>
#include <chrono>
class Solution {
private:
    void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    // for循环可以理解是横向遍历，backtracking（递归）就是纵向遍历
    // for (int i = startIndex; i <= n; i++) {
    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方
        path.push_back(i);
        backtracking(n, k, i+1); // 递归
        // path.clear();
        path.pop_back();
        }   
    }
public:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    std::vector<std::vector<int>> combine(int n, int k) {
        result.clear();
        path.clear(); 
        backtracking(n, k, 1);
        return result;
    }
};

int main(){
    Solution com;
    // 获取当前时间点
    auto start = std::chrono::high_resolution_clock::now();

    com.combine(50,5);

    // 获取当前时间点
    auto end = std::chrono::high_resolution_clock::now();
    
    // 计算代码的运行时间
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "代码运行时间为：" << duration << " 毫秒" << std::endl;
    return 0;
}
