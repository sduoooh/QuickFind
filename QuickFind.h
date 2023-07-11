#pragma once
#ifndef QF
#define QF

#include <string>
#include <map>
#include <vector>

#include <mutex>
#include <condition_variable>

#include <regex>
#include <iostream>

#define maps std::map <std::string, std::string>
#define vectors std::vector <std::string>

#define desktoppath "C:\\Users\\1\\Desktop"
#define srcpath "C:\\sources"
#define spypath "C:\\Users\\1\\Desktop"

extern std::mutex m;
extern std::condition_variable generater;
extern std::condition_variable finder;
extern std::condition_variable spyer;

extern bool isupdate;
extern bool issreach;
extern maps map;
extern vectors vector;


// 目录生成
void generrate(std::string, vectors&, maps&);
void create();

// 目录监视
void spy();

// 查找
void find();

#endif
