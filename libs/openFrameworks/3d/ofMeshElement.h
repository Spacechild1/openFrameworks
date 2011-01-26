// TODO:
// get face info properly
// use edge flags

#pragma once

#include "ofVec3f.h"
#include "ofVec2f.h"
#include "ofColor.h"
#include "ofUtils.h"

enum ofTriangleMode{
	OF_TRIANGLES_ELEMENT,
	OF_TRIANGLE_STRIP_ELEMENT,
	OF_TRIANGLE_FAN_ELEMENT,
};

inline GLuint ofGetGLTriangleMode(ofTriangleMode mode){
	switch(mode){
	case OF_TRIANGLES_ELEMENT:
		return GL_TRIANGLES;
		break;
	case OF_TRIANGLE_STRIP_ELEMENT:
		return GL_TRIANGLE_STRIP;
		break;
	case OF_TRIANGLE_FAN_ELEMENT:
		return GL_TRIANGLE_FAN;
		break;
	default:
		return GL_TRIANGLES;
	}
}

inline ofTriangleMode ofGetOFTriangleMode(GLuint mode){
	switch(mode){
	case GL_TRIANGLES:
		return OF_TRIANGLES_ELEMENT;
		break;
	case GL_TRIANGLE_STRIP:
		return OF_TRIANGLE_STRIP_ELEMENT;
		break;
	case GL_TRIANGLE_FAN:
		return OF_TRIANGLE_FAN_ELEMENT;
		break;
	default:
		ofLogError("of") << "asked for non existant triangle mode " << mode << " returning GL_TRIANGLES";
		return OF_TRIANGLES_ELEMENT;
	}
}

class ofMeshElement{
public:
	
	ofMeshElement();
	~ofMeshElement();
	
	void setMode(ofTriangleMode mode);
	ofTriangleMode getMode();
	
	void clear();

	void setupIndices();
//	void setupIndicesSolid();
//	void setupIndicesWire();
	
	ofVec3f getVertex(int i);
	void addVertex(const ofVec3f& v);
	void addVertices(const vector<ofVec3f>& verts);
	void addVertices(const ofVec3f* verts, int size);
	void removeVertex(int index);
	void setVertex(int index, const ofVec3f& v);
	
	ofVec3f getNormal(int i);
	void addNormal(const ofVec3f& n);
	void addNormals(const vector<ofVec3f>& norms);
	void addNormals(const ofVec3f* norms, int size);
	void removeNormal(int index);
	void setNormal(int index, const ofVec3f& n);
	
	ofColor getColor(int i);
	void addColor(const ofColor& c);
	void addColors(const vector<ofColor>& cols);
	void addColors(const ofColor* cols, int size);
	void removeColor(int index);
	void setColor(int index, const ofColor& c);
	
	ofVec2f getTexCoord(int i);
	void addTexCoords(const vector<ofVec2f>& tCoords);
	void addTexCoords(const ofVec2f* tCoords, int size);
	void addTexCoord(const ofVec2f& t);
	void removeTexCoord(int index);
	void setTexCoord(int index, const ofVec2f& t);
	
	int getIndex(int i);
	void addIndex(int i);
	void addIndices(const vector<GLuint>& inds);
	void addIndices(const GLuint* inds, int size);
	void removeIndex(int i);
	void setIndex(int i, int val);
	
	int getNumVertices() const;
	int getNumColors() const;
	int getNumNormals() const;
	int getNumTexCoords() const;
	int getNumIndices() const;
//	int getNumIndicesSolid();
//	int getNumIndicesWire();
	
	ofVec3f* getVerticesPointer();
	ofColor* getColorsPointer();
	ofVec3f* getNormalsPointer();
	ofVec2f* getTexCoordsPointer();
	GLuint* getIndexPointer();
//	GLuint* getSolidIndexPointer();
//	GLuint* getWireIndexPointer();

	vector<int>& getFace(int faceId);
	
	bool haveVertsChanged();
	bool haveColorsChanged();
	bool haveNormalsChanged();
	bool haveTexCoordsChanged();
	bool haveIndicesChanged();
	
protected:
	vector<ofVec3f> vertices;
	vector<ofColor> colors;
	vector<ofVec3f> normals;
	vector<ofVec2f> texCoords;
	vector<GLuint> indices;
	bool bVertsChanged, bColorsChanged, bNormalsChanged, bTexCoordsChanged, bIndicesChanged;
	ofTriangleMode mode;
	
//	vector<GLuint> indicesSolid;
//	vector<GLuint> indicesWire;
//	ofMaterial *mat;
};

