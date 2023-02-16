namespace bliplop {

    class BlipLop {
    public:
//        BlipLop();
//
//        ~BlipLop();

        void play();

        void stop();

        bool isPlaying() const;

    private:
        bool _isPlaying = false;
    };

}
