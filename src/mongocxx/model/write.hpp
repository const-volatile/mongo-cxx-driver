// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <mongocxx/config/prelude.hpp>

#include <cstdint>

#include <mongocxx/write_type.hpp>
#include <mongocxx/model/insert_one.hpp>
#include <mongocxx/model/delete_one.hpp>
#include <mongocxx/model/delete_many.hpp>
#include <mongocxx/model/update_one.hpp>
#include <mongocxx/model/update_many.hpp>
#include <mongocxx/model/replace_one.hpp>
#include <bsoncxx/stdx/optional.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace model {

class LIBMONGOCXX_API write {

   public:
    write(insert_one value);
    write(update_one value);
    write(update_many value);
    write(delete_one value);
    write(delete_many value);
    write(replace_one value);

    write(write&& rhs);
    write& operator=(write&& rhs);

    write(const write& rhs) = delete;
    write& operator=(const write& rhs) = delete;

    ~write();

    write_type type() const;

    const insert_one& get_insert_one() const;
    const update_one& get_update_one() const;
    const update_many& get_update_many() const;
    const delete_one& get_delete_one() const;
    const delete_many& get_delete_many() const;
    const replace_one& get_replace_one() const;

   private:
    void destroy_member();

    write_type _type;

    union {
        insert_one _insert_one;
        update_one _update_one;
        update_many _update_many;
        delete_one _delete_one;
        delete_many _delete_many;
        replace_one _replace_one;
    };
};

}  // namespace model
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>