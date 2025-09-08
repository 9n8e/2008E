namespace RBX {
    namespace Profiling {
        struct Bucket { 
        public:
            double sampleTimeSpan;
            int kernTimeSpan;
            int userTimeSpan;
            int frames;

            double getActualFPS() const;
            double getNominalFPS() const;
            double getFrameTime() const;
            double getTotalTime() const;
            Bucket();
            RBX::Profiling::Bucket& operator+=(const RBX::Profiling::Bucket&);
        };

        class Profiler {
        protected: 
            const double bucketTimeSpan;
            int currentBucket;
            RBX::Profiling::Bucket* buckets;
            double lastSampleTime;
            static int bucketCount;

        public: 
            const char* name;
            static double profilingWindow;
            static bool nonOverlapProfilingWindow;

            Profiler(const RBX::Profiling::Profiler&);
            Profiler(const char*);
            RBX::Profiling::Bucket getData(double) const;
            ~Profiler();
            RBX::Profiling::Profiler& operator=(const RBX::Profiling::Profiler&);

            static void setBucketCount(int);
            static void setProfilingWindow(double, bool);
        };

        class CodeProfiler : public RBX::Profiling::Profiler {
        private: 
            void log(int, int, bool);
            
        public: 
            RBX::Profiling::CodeProfiler* parent;
            CodeProfiler(const RBX::Profiling::CodeProfiler&);
            CodeProfiler(const char*);

            ~CodeProfiler();
            RBX::Profiling::CodeProfiler& operator=(const RBX::Profiling::CodeProfiler&);
        };
    }
}