//
// Created by osklot12 on 1/22/25.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>

namespace Graphics {
    // a graphical object
    class Object {
    public:
        // constructor for shared_ptr
        explicit Object(const std::shared_ptr<std::vector<float>>& vertices);

        // constructor for vector
        explicit Object(const std::vector<float>& vertices);

        // constructor for array
        template <std::size_t N>
        explicit Object(const std::array<float, N> &vertices) : vertices(std::make_shared<std::vector<float>>(vertices.begin(), vertices.end())) {}

        // destructor
        virtual ~Object() = default;

        // returns the vertices
        [[nodiscard]] const std::vector<float>& getVertices() const;
    private:
        // vertex data
        std::shared_ptr<const std::vector<float>> vertices;
    };
}


#endif //OBJECT_H
