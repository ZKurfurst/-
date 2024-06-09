目录结构：
├─object                  
│  ├─allocator       //不同分配策略具体实现
│  ├─allocator.h     //分配策略的模板类
│  └─object_pool.h   //对象池的模板类
│     
└─test_xxx          //具体分配策略的测试
    ├─a.h           //测试的类
    └─main.cpp      //测试主函数
