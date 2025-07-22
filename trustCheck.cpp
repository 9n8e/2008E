// my reconstruction
namespace RBX {
  class Http {
    public:
      static bool trustCheck(const char* url) {
        // somewhere around here is the definition for kSkipTrustCheck
        bool kSkipTrustCheck = 0;
        if (kSkipTrustCheck) {
          return true;
        }

        if (std::string("about:blank") == url || isRobloxSite(url) || isScript(url)) {
          return true;
        }

        // TBD
      }
      static bool isRobloxSite(const char* url) {
        // placeholder for syntax
      }
      static bool isScript(const char* url) {
        // placeholder for syntax
      }
  }
}
