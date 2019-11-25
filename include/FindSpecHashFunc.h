//
// Created by anton on 25.11.2019.
//
#include <PicoSHA2/picosha2.h>
#include <boost/log/trivial.hpp>
#include <string>
#include <thread>

struct Hash{
    std::string data;  // Contains data
    std::string hash;  // Contains data converted to Hash
    std::string end;   // Contains hash end
};

void FindSpecificHash(const std::string &needed_hash_end)
{
    auto thread_id = std::this_thread::get_id();  // Thread id
    Hash curr_hash;

    //int counter=0; // Unomment to make not endless
    while (true)
    {
        curr_hash.data = std::to_string(std::rand());
        curr_hash.hash = picosha2::hash256_hex_string(curr_hash.data);
        curr_hash.end = curr_hash.hash.substr(curr_hash.hash.size() - needed_hash_end.size());

        if (curr_hash.end == needed_hash_end)
            BOOST_LOG_TRIVIAL(info) << "Thread id: " << thread_id << " Satisfies: +  Data: '" << curr_hash.data << "' Hash: '" << curr_hash.hash<<"'";
        else
            BOOST_LOG_TRIVIAL(info) << "Thread id: " << thread_id << " Satisfies: -  Data: '" << curr_hash.data << "' Hash: '" << curr_hash.hash<<"'";

        //counter++;  // Unomment to make not endless
    }

}