namespace RBX {
    class Replicator {
    public:
        Replicator(SystemAddress remotePlayerId, RakPeerInterface* rakPeer) {
            //blablabla
            std::string playerIp = SystemAddress::ToString(&remotePlayerId, true);
            RBX::Instance::setName(this, &playerIp);
            // blablalba
        }
    }
}