#include <iostream>
#include <deque>
#include <stack>

class MedianFinder
{
public:
  void addNum(int num) {
    if (dq.empty())
      dq.push_back(num);
    else {
      // solution 1
      // int med = findMedian();
      // if (num <= med) {
      // 	std::stack<int> temp;
      // 	while (dq.front() < num) {
      // 	  temp.push(dq.front());
      // 	  dq.pop_front();
      // 	}
      // 	dq.push_front(num);
      // 	while (!temp.empty()) {
      // 	  dq.push_front(temp.top());
      // 	  temp.pop();
      // 	}
      // }
      // else {
      // 	std::stack<int> temp;
      // 	while (dq.back() > num) {
      // 	  temp.push(dq.back());
      // 	  dq.pop_back();
      // 	}
      // 	dq.push_back(num);
      // 	while (!temp.empty()) {
      // 	  dq.push_back(temp.top());
      // 	  temp.pop();
      // 	}
      // }

      // solution 2
      auto it = dq.begin();
      while (it != dq.end() && *(it+1) < num)
	++it;
      dq.insert(it, num);
    }
  }

  double findMedian() {
    if (dq.size() > 0) {
      if (dq.size()%2)
	return dq[dq.size()/2];
      else
	return (dq[dq.size()/2-1]+dq[dq.size()/2])/2.0;
    }
    else
      std::cout << "There is no number!" << std::endl;
  }

private:
  std::deque<int> dq;
};

int main()
{
  MedianFinder mf;
  mf.addNum(1);
  std::cout << "Median = "
	    << mf.findMedian() << std::endl;

  mf.addNum(2);
  std::cout << "Median = "
	    << mf.findMedian() << std::endl;

  mf.addNum(5);
  std::cout << "Median = "
	    << mf.findMedian() << std::endl;

  mf.addNum(3);
  std::cout << "Median = "
	    << mf.findMedian() << std::endl;

  mf.addNum(4);
  std::cout << "Median = "
	    << mf.findMedian() << std::endl;

  return 0;
}

