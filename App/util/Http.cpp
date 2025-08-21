#include "util/Http.h"

namespace RBX {
    void httpGetPost(bool isPost, std::string* url, std::istream* data, bool compressData, std::string additionalHeaders, std::string* response);

    class Http {
    public:
        std::string url;
        std::string additionalHeaders;

        Http(std::string url) {
            this->url = url;
        }

        void post(std::istream* input, bool compress, std::string* response) {
            std::string p_Bx;

            if (this->additionalHeaders.size()) {
                if (this->additionalHeaders.size() < 0x10) {
                    p_Bx = this->additionalHeaders.size();
                } else {
                    p_Bx = this->additionalHeaders.data();
                    RBX::httpGetPost(true, &this->url, input, compress, p_Bx, response);
                }
            } else {
                RBX::httpGetPost(true, &this->url, input, compress, 0, response);
            }
        }
    }
}