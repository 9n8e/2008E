void __cdecl RBX::Render::Mesh::beginRender(G3D::RenderDevice *rd, bool usetexCoords, bool useTangent)
{
  RBX::Render::Mesh::makeVAR();
  G3D::RenderDevice::beginIndexedPrimitives(rd);
  if ( G3D::VAR::valid(&RBX::Render::Mesh::vertexVAR) )
    G3D::RenderDevice::setVertexArray(rd, &RBX::Render::Mesh::vertexVAR);
  if ( G3D::VAR::valid(&RBX::Render::Mesh::normalVAR) )
    G3D::RenderDevice::setNormalArray(rd, &RBX::Render::Mesh::normalVAR);
  if ( usetexCoords && G3D::VAR::valid(&RBX::Render::Mesh::texCoordVAR) )
    G3D::RenderDevice::setTexCoordArray(rd, 0, &RBX::Render::Mesh::texCoordVAR);
  if ( useTangent && G3D::VAR::valid(&RBX::Render::Mesh::tangentVAR) )
    G3D::RenderDevice::setTexCoordArray(rd, 2u, &RBX::Render::Mesh::tangentVAR);
}
