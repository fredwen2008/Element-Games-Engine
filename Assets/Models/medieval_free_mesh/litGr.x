xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro v3.27
// Website: http://www.unwrap3d.com
// Time: Wed May 25 11:18:24 2011

// Start of Templates

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template FVFData {
 <b6e70a0e-8ef9-4e83-94ad-ecc8b0c04897>
 DWORD dwFVF;
 DWORD nDWords;
 array DWORD data[nDWords];
}

template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template FloatKeys {
 <10DD46A9-775B-11cf-8F52-0040333594A3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <F406B180-7B3B-11cf-8F52-0040333594A3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10DD46A8-775B-11cf-8F52-0040333594A3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template AnimationOptions {
 <E2BF56C0-840F-11cf-8F52-0040333594A3>
 DWORD openclosed;
 DWORD positionquality;
}

template Animation {
 <3D82AB4F-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template AnimationSet {
 <3D82AB50-62DA-11cf-AB39-0020AF71E433>
 [Animation]
}

template XSkinMeshHeader {
 <3CF169CE-FF7C-44ab-93C0-F78F62D172E2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template SkinWeights {
 <6F0D123B-BAD2-4167-A0D0-80224F25FABB>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template AnimTicksPerSecond {
 <9E415A43-7BA6-4a73-8743-B73D47E88476>
 DWORD AnimTicksPerSecond;
}

AnimTicksPerSecond {
 4800;
}

// Start of Frames

Frame litGr {
   FrameTransformMatrix {
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000;;
   }

   Mesh litGr {
    144;
    -0.337399; 0.381289; 0.003346;,
    0.253813; 0.124141; 0.425351;,
    -0.091429; 0.544114; 0.461450;,
    0.007843; -0.038684; -0.032753;,
    -0.057432; 0.246463; -0.281163;,
    -0.139398; 0.208598; 0.282444;,
    -0.213091; 0.488873; 0.001521;,
    0.016262; -0.033811; -0.000240;,
    0.073393; 0.473301; -0.179265;,
    -0.334315; 0.117870; 0.369542;,
    -0.282733; 0.633359; 0.200773;,
    0.021810; -0.042188; -0.010496;,
    -0.243443; 0.395030; -0.276600;,
    -0.214291; 0.137881; 0.449189;,
    -0.454500; 0.557854; 0.198600;,
    -0.003233; -0.024943; -0.026012;,
    0.152972; 0.260203; -0.229893;,
    -0.342508; 0.222339; 0.050946;,
    -0.165779; 0.502613; -0.179523;,
    -0.023756; -0.020071; 0.000575;,
    0.103641; 0.521141; -0.031145;,
    -0.528519; 0.084047; -0.086536;,
    -0.425643; 0.618263; -0.116578;,
    0.000765; -0.013075; -0.001103;,
    0.106810; 0.397471; -0.360999;,
    -0.505009; 0.140322; 0.030533;,
    -0.409943; 0.560296; -0.303320;,
    0.011744; -0.022502; -0.027146;,
    0.266594; 0.262645; 0.004782;,
    -0.225949; 0.224780; -0.281176;,
    0.062211; 0.505054; -0.244953;,
    -0.021566; -0.017630; -0.031441;,
    -0.043836; 0.536157; 0.002054;,
    -0.194692; -0.010768; -0.519350;,
    -0.233495; 0.532605; -0.508720;,
    -0.005034; -0.007216; -0.008576;,
    0.338519; 0.396099; 0.041789;,
    -0.154534; 0.138950; -0.491614;,
    0.190836; 0.558924; -0.456760;,
    -0.006851; -0.023874; 0.006934;,
    0.006550; 0.261273; 0.263427;,
    0.201405; 0.223408; -0.271739;,
    0.216437; 0.503682; 0.018300;,
    -0.008482; -0.019002; -0.026612;,
    -0.088942; 0.517854; -0.066288;,
    0.445571; 0.005418; -0.279478;,
    0.381606; 0.543135; -0.339818;,
    -0.024976; -0.019863; -0.005949;,
    0.219187; 0.395030; 0.278865;,
    0.258849; 0.137881; -0.446426;,
    0.474267; 0.557855; -0.174230;,
    0.003769; -0.024943; 0.006669;,
    -0.171029; 0.260204; 0.194854;,
    0.348803; 0.222339; -0.037836;,
    0.151059; 0.502613; 0.174874;,
    0.026715; -0.020071; -0.017856;,
    -0.109932; 0.519737; 0.023031;,
    0.520761; 0.086798; 0.115418;,
    0.408790; 0.618369; 0.157461;,
    0.002038; -0.011834; -0.019013;,
    0.110893; 0.695450; -0.228012;,
    -0.500927; 0.337715; 0.074391;,
    -0.405860; 0.835197; -0.126475;,
    0.015827; 0.197969; -0.027146;,
    0.270677; 0.462314; 0.084432;,
    -0.221866; 0.507202; -0.200508;,
    0.066294; 0.765656; -0.086195;,
    -0.017483; 0.203860; -0.029881;,
    -0.039753; 0.747601; 0.025878;,
    -0.190609; 0.219047; -0.514139;,
    -0.229412; 0.761727; -0.484713;,
    -0.000951; 0.204922; -0.003549;,
    0.236303; 0.695450; 0.000693;,
    -0.241475; 0.337715; -0.486645;,
    -0.020999; 0.835197; -0.458806;,
    0.015827; 0.197969; -0.027146;,
    -0.010905; 0.462314; 0.249772;,
    0.106615; 0.507202; -0.306985;,
    0.087649; 0.765656; 0.002440;,
    0.008060; 0.203860; -0.059653;,
    -0.051860; 0.747601; -0.063466;,
    0.414400; 0.219047; -0.374878;,
    0.374360; 0.761727; -0.402597;,
    -0.011820; 0.204922; -0.035747;,
    0.077828; 0.695450; 0.186256;,
    0.335369; 0.337715; -0.445759;,
    0.397370; 0.835196; -0.232356;,
    0.015827; 0.197969; -0.027146;,
    -0.248937; 0.462314; 0.058284;,
    0.308708; 0.507202; -0.054947;,
    0.017194; 0.765656; 0.050519;,
    0.042577; 0.203860; -0.047183;,
    0.022282; 0.747601; -0.103690;,
    0.493240; 0.219047; 0.200570;,
    0.502780; 0.761727; 0.152815;,
    0.012742; 0.204922; -0.055935;,
    -0.178063; 0.695450; 0.081442;,
    0.495784; 0.337715; 0.189616;,
    0.301893; 0.835197; 0.298203;,
    0.015827; 0.197969; -0.027146;,
    -0.127183; 0.462314; -0.265781;,
    0.109046; 0.507202; 0.251892;,
    -0.059524; 0.765656; -0.008277;,
    0.041386; 0.203860; -0.005611;,
    0.091852; 0.747601; -0.038142;,
    -0.098203; 0.219047; 0.489357;,
    -0.049527; 0.761727; 0.487867;,
    0.043176; 0.204922; -0.036652;,
    -0.164673; 0.695450; -0.156779;,
    0.022797; 0.337715; 0.499442;,
    -0.157702; 0.835196; 0.369810;,
    0.015827; 0.197969; -0.027146;,
    0.171408; 0.462314; -0.257782;,
    -0.197447; 0.507202; 0.175503;,
    -0.033186; 0.765656; -0.087408;,
    0.007148; 0.203860; 0.005129;,
    0.057993; 0.747601; 0.037062;,
    -0.500347; 0.219047; 0.088365;,
    -0.478377; 0.761727; 0.131826;,
    0.036023; 0.204922; -0.006399;,
    -0.380722; 0.837741; 0.081442;,
    0.377109; 0.749785; 0.189615;,
    0.015458; 1.142583; 0.298203;,
    -0.019072; 0.444943; -0.027146;,
    -0.248482; 0.639111; -0.265781;,
    -0.044791; 0.766896; 0.251892;,
    -0.295864; 0.946274; -0.008277;,
    0.002591; 0.459733; -0.005611;,
    -0.148299; 0.984550; -0.038142;,
    -0.132952; 0.423075; 0.489357;,
    -0.285122; 0.946253; 0.487867;,
    0.003871; 0.461373; -0.036652;,
    0.230016; 0.764496; -0.391445;,
    -0.256650; 0.882475; 0.194202;,
    -0.007562; 1.202028; -0.170098;,
    -0.019072; 0.444943; -0.027146;,
    0.355594; 0.492262; -0.095433;,
    -0.093667; 0.829478; -0.196693;,
    0.302265; 0.851285; -0.271956;,
    -0.040337; 0.470455; -0.020169;,
    0.269358; 0.907575; -0.130956;,
    -0.373784; 0.577079; -0.397203;,
    -0.088233; 1.023029; -0.525509;,
    -0.016193; 0.461626; -0.002650;;
    72;
    3;0, 1, 2;,
    3;0, 3, 1;,
    3;4, 5, 6;,
    3;4, 7, 5;,
    3;8, 9, 10;,
    3;8, 11, 9;,
    3;12, 13, 14;,
    3;12, 15, 13;,
    3;16, 17, 18;,
    3;16, 19, 17;,
    3;20, 21, 22;,
    3;20, 23, 21;,
    3;24, 25, 26;,
    3;24, 27, 25;,
    3;28, 29, 30;,
    3;28, 31, 29;,
    3;32, 33, 34;,
    3;32, 35, 33;,
    3;36, 37, 38;,
    3;36, 39, 37;,
    3;40, 41, 42;,
    3;40, 43, 41;,
    3;44, 45, 46;,
    3;44, 47, 45;,
    3;48, 49, 50;,
    3;48, 51, 49;,
    3;52, 53, 54;,
    3;52, 55, 53;,
    3;56, 57, 58;,
    3;56, 59, 57;,
    3;60, 61, 62;,
    3;60, 63, 61;,
    3;64, 65, 66;,
    3;64, 67, 65;,
    3;68, 69, 70;,
    3;68, 71, 69;,
    3;72, 73, 74;,
    3;72, 75, 73;,
    3;76, 77, 78;,
    3;76, 79, 77;,
    3;80, 81, 82;,
    3;80, 83, 81;,
    3;84, 85, 86;,
    3;84, 87, 85;,
    3;88, 89, 90;,
    3;88, 91, 89;,
    3;92, 93, 94;,
    3;92, 95, 93;,
    3;96, 97, 98;,
    3;96, 99, 97;,
    3;100, 101, 102;,
    3;100, 103, 101;,
    3;104, 105, 106;,
    3;104, 107, 105;,
    3;108, 109, 110;,
    3;108, 111, 109;,
    3;112, 113, 114;,
    3;112, 115, 113;,
    3;116, 117, 118;,
    3;116, 119, 117;,
    3;120, 121, 122;,
    3;120, 123, 121;,
    3;124, 125, 126;,
    3;124, 127, 125;,
    3;128, 129, 130;,
    3;128, 131, 129;,
    3;132, 133, 134;,
    3;132, 135, 133;,
    3;136, 137, 138;,
    3;136, 139, 137;,
    3;140, 141, 142;,
    3;140, 143, 141;;

   MeshTextureCoords {
    144;
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;,
    0.000000; 1.000000;,
    1.000000; 0.000000;,
    0.000000; 0.000000;,
    1.000000; 1.000000;;
   }

   MeshMaterialList {
    1;
    72;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;

    Material _6 {
     0.800000; 0.800000; 0.800000; 1.000000;;
     128.000000;
     0.000000; 0.000000; 0.000000;;
     0.000000; 0.000000; 0.000000;;

     TextureFilename {
      "C:\\new packs\\FREE PACK\\mesh\\litGrC.tga";
     }
    }

   }
  }
}