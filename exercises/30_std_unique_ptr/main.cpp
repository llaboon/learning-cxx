#include "../exercise.h"
#include <memory>
#include <cstring>
#include <vector>
//#include<bits/stdc++.h>
// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    if (ptr) {
        ptr->record('r');
    }
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    if (ptr) {
        ptr->record('d');
    }
    return nullptr;
}
Unique forward(Unique ptr) {
    if (ptr) {
        ptr->record('f');
    }
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);
    //std::string s="ffr";
    //std::cout<<problems[1].size()<<problems[1][1]<<std::endl;
    // ---- 不要修改以上代码 ----

    std::vector<const char *> answers[]{
        {"fd"},
        // TODO: 分析 problems[1] 中资源的生命周期，将记录填入 `std::vector`
        {"ffr","d"},
        {"r", "d","d"},
    };
    /*for (auto i = 0; i < 3; ++i) {
        std::cout<<(problems[i].size() == answers[i].size());
        for (auto j = 0; j < problems[i].size(); ++j) {
            std::cout<<(strcmp(problems[i][j].c_str(), answers[i][j]) == 0)<<std::endl;
            std::cout<<problems[i][j].c_str()<<" "<<answers[i][j]<<std::endl;
        }
    }*/
    //std::cout<<"hello";
    //std::cout<<problems[0].size()<<std::endl<<answers[0].size()<<problems[1].size()<<answers[1].size()<<problems[2].size()<<answers[2].size();
    // ---- 不要修改以下代码 ----

    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    return 0;
}
