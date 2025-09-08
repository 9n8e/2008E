#include <string>

namespace RBX {
    class Http {
        public:
            const std::string url;
            std::string additionalHeaders;

            Http(const std::string* url);
            void post(std::istream* input, bool compress, std::string* response);
    };
}