#include <list>
#include <string>

namespace RBX {
    class ContentProvider {
        enum HttpRequestType {
            NoHttpRequest = 0x0000,
            AsyncHttpRequest = 0x0001,
            SyncHttpRequest = 0x0002
        };
    private:
        /*boost::mutex requestSync;
        std::list<RBX::ContentId, RBX::ContentId> requestQueue;
        std::list<RBX::ContentId::FailedUrl, RBX::ContentProvider::FailedUrl> failedUrls;
        boost::mutex contentCacheMutex;*/
        static std::string assetFolderPath;
    public:
        
    }
}