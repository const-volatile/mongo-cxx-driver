#include "catch.hpp"
#include "helpers.hpp"

#include <mongocxx/model/update_many.hpp>



TEST_CASE("update_many", "[update_many][model]") {
    const bsoncxx::document::view a((std::uint8_t *)"", 0);
    const bsoncxx::document::view b((std::uint8_t *)"", 0);

    driver::model::update_many um(a, b);

    SECTION("stores required arguments") {
        REQUIRE(um.filter().data() == a.data());
        REQUIRE(um.update().data() == b.data());
    }

    CHECK_OPTIONAL_ARGUMENT(um, upsert, true)
}