#ifndef FHC_START_H
#define FHC_START_H

class FHC_Start
{
public :
	FHC_Start() {};
	~FHC_Start() {};
	void outStart(); //这里不写大括号

private:
	int n; //给n赋初始值不起作用
	unsigned long long ans1, ans2;
};

#endif
