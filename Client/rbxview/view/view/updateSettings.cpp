void __thiscall RBX::View::View::updateSettings(
        RBX::View::View *this,
        float shadingQuality,
        float meshDetail,
        bool shadows,
        float cameraDistance)
{
  RBX::Render::RenderScene::setThrottle(
    (RBX::Render::RenderScene *)this->renderLibScene._Myptr,
    shadingQuality,
    meshDetail,
    shadows,
    cameraDistance);
}
