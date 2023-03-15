namespace bliplop {

    class BlipLop {
    public:
//        BlipLop();
//
//        ~BlipLop();

        void play();

        void stop();

        bool isPlaying() const;

        // gain factor
        void setGain();
        // low pass filter
        // high pass filter

    private:
        bool _isPlaying = false;
        int source;
        int sink;
    };

}
