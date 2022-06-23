'''
{
	MeshExporter Version 0.1a
	convertex OBJ file to Binary mesh file (AOS-array of structures format)
	{
		Structure{
			4 bytes -> total vertex size
			4 bytes -> total index size
			4 bytes -> is vertex coords available
			4 bytes -> is nromals available
		}
	}
}
'''
'''
{
	arguments :
	1 -> mesh full path or relative path
	2 -> location where the bianry file should be saved
}
'''
'''
{
	Example -> example obj file location -> /home/teja/Desktop/BeveledCube.obj
	Example -> destination path -> /home/teja/Desktop/
}
'''
import sys, struct
ObjFileLoc = sys.argv[1]
OBJFile = open(ObjFileLoc, 'r')
MainLines = OBJFile.readlines()

smoothshading = ""
vertexDataLines = []
vertexTextDataLines = []
vertexNormalDataLines = []
indexDataLines = []
meshnameline = ""
for i in range(len(MainLines)):
	templine = MainLines[i]
	if(templine[0:2] == 'v '):
		vertexDataLines.append(templine)
	elif(templine[0:2] == 'vt'):
		vertexTextDataLines.append(templine)
	elif(templine[0:2] == 'vn'):
		vertexNormalDataLines.append(templine)
	elif(templine[0:2] == 'f '):
		indexDataLines.append(templine[0:(len(templine)-1)])
	elif(templine[0:2] == 's '):
		smoothshading = templine
	elif(templine[0:2] == 'o '):
		meshnameline = templine[2:len(templine)-1]

print(str(len(vertexDataLines)) +"  "+(str)(len(vertexTextDataLines)) +"  " +str(len(vertexNormalDataLines)) +"  "+str(len(indexDataLines)))

#
# Creating Binary Mesh File
#
points = []
print("-"*30)
for i in range(len(indexDataLines)):
	temp = indexDataLines[i].split(' ')
	points.append(temp[1])
	points.append(temp[2])
	points.append(temp[3])

for i in range(len(points)):
	for j in range(len(points)):
		if(j == i):
			continue
		else:
			if(points[i] == points[j]):
				print(points[j] + "Found multiple times")
			# else:
			# 	print(points[j] + "only occured once")
indices = []
dict = {1:"Text"}
dict.clear()

for i in range(len(points)):
	if(points[i] not in indices):
		indices.append(points[i])

for i in range(len(indices)):
	dict[indices[i]] = i


print(dict)

actualIndices = []

for i in range(len(points)):
	actualIndices.append(dict[points[i]])

rawVertexData = []
for i in range(len(indices)):
	tempind = indices[i].split('/')
	rawVertexData.append(vertexDataLines[((int)(tempind[0]))-1])
	rawVertexData.append(vertexTextDataLines[((int)(tempind[1]))-1])
	rawVertexData.append(vertexNormalDataLines[((int)(tempind[2]))-1])

actualvertexdata = []

for i in range(len(rawVertexData)):
	tempvert = rawVertexData[i].split(' ')
	for j in range(len(tempvert)):
		if(j == 0):
			continue
		else:
			actualvertexdata.append((float)(tempvert[j]))

DestinationMeshFile = sys.argv[2] + "/" + meshnameline + ".b_mesh"

open(DestinationMeshFile, 'w')

binaryMeshFile = open(DestinationMeshFile, 'ab')

binaryMeshFile.write(struct.pack('i', len(actualvertexdata)))
binaryMeshFile.write(struct.pack('i', len(actualIndices)))
binaryMeshFile.write(struct.pack('i', 1))
binaryMeshFile.write(struct.pack('i', 1))

for i in range(len(actualvertexdata)):
	binaryMeshFile.write(struct.pack('f', actualvertexdata[i]))
for i in range(len(actualIndices)):
	binaryMeshFile.write(struct.pack('i', actualIndices[i]))

binaryMeshFile.close()