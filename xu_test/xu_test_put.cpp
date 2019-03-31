//
// Created by xuxue on 19-3-31.
//
#include "leveldb/db.h"
#include <iostream>

int main() {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    leveldb::Status put = db->Put(leveldb::WriteOptions(), "test", "Hahahaha");
    std::string value;
    if (put.ok()) {
        leveldb::Status readStatus = db->Get(leveldb::ReadOptions(), "test", &value);
        if(readStatus.ok()) {
            std::cout<< value << std::endl;
        }
    }
    delete db;
}
