이 파일은 [https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution)을 번역한 것입니다. 영어가 서툴러 번역이 잘못되었을 수 있습니다. 번역이 잘못된 부분을 발견하신다면 지적해주시면 감사하겠습니다.

- # 3. Ray-Triangle Intersection : Geometric Solution

## Ray-Triangle Intersection : Geometric Solution
---
이전 단락에서 우리는 평면의 법선 (삼각형의 법선과 동일)을 계산하는 방법을 배웠습니다. 다음으로 우리가 알아 내야 할 것은 점 P의 위치입니다 (일부 그림에서는 Phit도 사용했습니다). 광선이 평면과 교차하는 점입니다.

### 1단계 : P 찾기

우리는 P가 그 원점(O)와 방향(R)에 의해 정의된 광선의 어딘가에 있다는 것을 압니다(이전 평면 강의에서는 R이 아닌 D를 썼지만, 평면과 헷갈리지 않게 R을 쓸 것입니다). 광선 매개 변수 방정식은 다음과 같습니다 (equation1).

*P = O + tR* (equation1)

![그림 1 : 광선과 삼각형의 교차점. 삼각형은 평면 위에 있습니다. t의 값은 광선 원점에서 교차점까지의 거리입니다.](https://www.scratchapixel.com/images/upload/ray-triangle/triray2.png?)
*t*는 점 *P*가 광선 원점으로부터 떨어진 거리입니다. *P*를 찾으려면 *t*를 찾아야 합니다(그림 1). 우리는 또 무엇을 알고 있습니까? 우리는 이미 계산 한 평면의 법선과 다음과 같은 평면 방정식(equation2)을 알고 있습니다 (이 항목에 대한 자세한 내용은 이전의 [ray-plane intersection](../04.Ray-Plane_and_Ray-Disk_intersection.md)에 대한 장을 확인하십시오).

*Ax + By + Cz = D* (equation2)

여기서 A, B, C는 평면에 대한 법선(*N~plane~ = (A, B, C))*의 구성 요소(또는 좌표)로 볼 수 있고 D는 원점(0, 0, 0)에서 평면까지의 거리입니다 (원점에서 평면까지 선을 추적하는 경우 평면의 법선에 평행). 변수 *x, y* 및 *z*는이 평면에있는 모든 점의 좌표입니다.

우리는 평면 법선을 알고 있으며 세 삼각형의 정점(vertices ; V0, V1, V2)이 평면에 있다는 것을 알고 있습니다. 따라서 D 값을 계산할 수 있습니다. 세 개의 정점 중 하나를 선택할 수 있지만 규칙에 따라 첫 번째 V0을 사용합니다.
```cpp
float D = dotProduct(N, v0); 
// or if you want to compute the dot product directly
float D = N.x * v0.x + N.y * v0.y + N.z * v0.z; 
```

우리는 또한 광선과 평면의 교차점 인 점 P가 평면에 있다는 것을 알고 있습니다. 결과적으로 equation2에서 *x, y, z*를 *P~x~, P~y~, P~z~*로 대체하고 이를 *t*(equation3)에 대하여 풀 수 있습니다.

*P = O + tR*

*A~x~* + *B~y~* + *C~z~* + *D* = *0*

*A* ∗ *P~x~* + *B* ∗ *P~y~* + *C* ∗ *P~z~* + *D* = *0*

*A* ∗ (*O~x~* + *tR~x~*) + *B* ∗ (*O~y~* + *tR~y~*) + *C* ∗ (*O~z~* + *tR~z~*) + *D* = *0*

*A* ∗ *O~x~* + *B* ∗ *O~y~* + *C* ∗ *O~z~* + *A* ∗ *tR~x~* + *B* ∗ *tR~y~* + *C* ∗ *tR~z~* + *D* = *0*

*t* ∗ (*A* ∗ *R~x~* + *B* ∗ *R~y~* + *C* ∗ *R~z~*) + *A* ∗ *O~x~* + *B* ∗ *O~y~* + *C* ∗ *O~z~* + *D* = *0*

*t* = (*−A* ∗ *O~x~* + *B* ∗ *O~y~* + *C* ∗ *O~z~* + *D*) / (*A* ∗ *R~x~* + *B* ∗ *R~y~* + *C* ∗ *R~z~*)

*t* = (*−N*(*A*, *B*, *C*) ⋅ *O* + *D*) / (*N*(*A* ,*B*, *C*) ⋅ *R*)*

이 기술을 구현할 때 주의하십시오. 기본적으로 카메라의 방향은 음의 z축을 따라 설정되므로 모든 기본 광선(카메라가 기본 위치에 있다고 가정)은 음의 Z 좌표를 갖습니다. 이것은 또한 삼각형의 법선이 카메라를 향할 때 광선과 법선의 내적(*(N(A ,B, C) ⋅ R)*)이 음수임을 의미합니다. 따라서 방정식 앞의 음수 기호는 분모의 음수 기호에 의해 제거됩니다. 실제로 이것은 분모를 음수로 바꿔야 함을 의미하므로 다음과 같이 끝납니다.

*t* = −(*N*(*A*, *B*, *C*) ⋅ *O* + *D*) / (-*N*(*A*, *B*, *C*) ⋅ *R*)
    = (*N*(*A*, *B*, *C*) ⋅ *O* + *D*) / (*N*(*A*, *B*, *C*) ⋅ *R*)

이 장 끝에있는 실제 코드에서 실제 예제를 확인하십시오.

```cpp
float t =-(dot (N, orig) + D) / dot (N, dir);
```

이제 우리는 t를 이용하여 p의 위치를 구할 수 있습니다.

```cpp
Vec3f Phit = orig + t * dir;
```

#### 광선과 삼각형이 평행할 때

광선과 평면이 평행하면 교차하지 않습니다(그림 2). 확실함을 위해 우리는 이런 경우를 처리해야합니다. 이것은 매우 간단합니다. 삼각형이 광선 방향과 평행하면 삼각형의 법선과 광선의 방향이 수직이어야 함을 의미합니다.

![그림 2 : 여러 상황이 발생할 수 있습니다. 광선은 삼각형을 교차하거나 놓칠 수 있습니다. 광선이 삼각형에 평행하면 교차가 불가능합니다. 이 상황은 삼각형의 법선과 광선 방향이 수직 일 때 발생합니다 (이 두 벡터의 내적은 0).](https://www.scratchapixel.com/images/upload/ray-triangle/trirays.png?)

두 수직 벡터의 내적은 0이라는 것을 배웠습니다. equation의 분모를 보면 삼각형의 법선 *N*과 광선 방향 *D* 사이의 내적을 이미 계산했습니다. 사실 우리 코드는 이 항이 잠재적으로 0이 될 수 있고 그렇게 되면 분자를 0으로 나누게 되기 때문에 정확하지 않습니다. 분모가 0일 때 광선은 삼각형과 평행합니다. 이 경우 교차하지 않으므로 *t*를 계산할 필요가 없습니다. 결론적으로 *t*를 계산하기 전에 우리 코드에서 우리는 분모(*N ⋅ R*)의 결과를 계산할 것입니다. 분모가 0이면 함수는 false(교차하지 않음)를 반환합니다.

#### 삼각형이 광선 뒤에 있을 때

지금까지 우리는 삼각형이 항상 광선 앞에 있다고 가정했습니다. 그러나 광선이 여전히 같은 방향을보고있는 상태에서 삼각형이 광선 뒤에 있으면 어떻게 될까요? 일반적으로 삼각형은 보이지 않아야 합니다. 삼각형이 광선 "뒤"에 있을 때도 equation3을 사용하여 유효한 값을 얻습니다. 이 경우, *t*는 음수이고 교차점이 광선의 반대 방향에 있게 됩니다. 이러한 "오류"를 확인하지 않으면, 원하지 않는 삼각형이 최종 이미지에 표시됩니다. 따라서 우리는 교차점이 유효한지 여부를 결정하기 전에 먼저 t가 0보다 큰지 작은지를 판단해야 합니다. *t*가 음수라면 교차점이 없으며 함수를 종료할 수 있습니다. 만약 *t* 0보다 크면 해당 광선에 대하여 삼각형이 표시되고 다음 단계를 진행할 수 있습니다.

![그림 3 : 삼각형이 광선 "뒤에"있으면 보이지 않아야합니다. equation3으로 계산 된 t의 값이 0보다 낮을 때마다 교차점은 광선의 원점 뒤에 위치하므로 버려야합니다. 이 경우 교차점이 없습니다.](https://www.scratchapixel.com/images/upload/ray-triangle/tribehind.png?)

### 2단계 : P가 삼각형의 내부에 있는지 확인

이제 우리는 광선과 평면이 교차하는 지점 인 점 P를 찾았으므로 P가 삼각형 내부에 있는지 (이 경우에 광선과 삼각형이 교차하고) 또는 P가 외부에 있는지 알아 내야합니다. (이 경우에는 광선과 삼각형이 교차하지 않습니다). 그림 2는 이 두 가지 경우를 보여줍니다.

이 문제에 대한 해결책은 간단하며 "내부 - 외부" 테스트라고도 합니다(이미 rasterization에 대한 강의에서 이 용어를 사용했습니다. 비록 두 테스트 모두 점이 삼각형에 있는지 확인하는 기능을 가지고 있지만 rasterization에서의 테스트는 2D 삼각형에 대해 작동하고, 앞으로 설명할 방법은 3D에서 작동합니다). x축과 정렬된 벡터 A가 있다고 상상해 보십시오. (그림 4). 이 벡터가 실제로 삼각형의 한 가장자리(두 정점 V0V1로 정의 된 가장자리)와 정렬되어 있다고 가정해봅시다. 두 번째 모서리 B는 그림 4와 같이 삼각형의 정점 V0 및 V2로 정의됩니다. 이 두 벡터의 외적을 계산해 보겠습니다. 예상대로 결과는 z 축과 삼각형의 법선과 같은 방향을 가리키는 벡터입니다.

![그림 4 : C와 C '는 반대 방향을 가리 킵니다.](https://www.scratchapixel.com/images/upload/ray-triangle/triinsideout1.png?)

*A = (1, 0, 0)*
*B = (1, 1, 0)*
*C~x~ = A~y~B~z~ − A~z~B~y~ = 0*
*C~y~ = A~z~B~x~ − A~x~B~z~ = 0*
*C~z~ = A~x~B~y~ − A~y~B~x~= 1 ∗ 1 − 0 ∗ 1 = 1*
*C = (0, 0, 1)*

이제 좌표 정점 V2의 좌표가 (1, 1, 0)이 아니라 (1, -1, 0)이라고 상상해 봅시다. 즉, V2를 x축에 대해 대칭이동 했습니다. 이제 외적 *A x B*를 계산하면 *C'*= (0, 0, -1)의 결과를 얻습니다.

*A = (1, 0, 0)*
*B = (1, -1, 0)*
*C~x~ = A~y~B~z~ − A~z~B~y~ = 0*
*C~y~ = A~z~B~x~ − A~x~B~z~ = 0*
*C~z~ = A~x~B~y~ − A~y~B~x~= 1 ∗ -1 − 0 ∗ 1 = -1*
*C = (0, 0, -1)*

![그림 5 : P가 A의 왼쪽에 있으면 내적 NC는 양수입니다. P가 오른쪽 (P ')에 있으면 NC'는 음수입니다. 벡터 C는 v0 및 P (C = P-v0)에서 계산됩니다.](https://www.scratchapixel.com/images/upload/ray-triangle/triinsideout2.png?)

C는 N과 같은 방향을 가리키기 때문에 내적은 0보다 큰 값(양수)을 반환합니다. 그러나 C'과 N은 반대 방향을 가리키기 때문에 내적은 0보다 낮은 값(음수)을 반환합니다. 이 테스트는 무엇을 의미할까요? 우리는 광선이 삼각형과 교차하는 지점과 삼각형이 같은 평면에 있다는 것을 알고 있습니다. 우리는 또한 방금 전의 테스트를 통해 삼각형의 평면(예 : 정점 V2 또는 교차점)에 있는 점 P가 벡터 A의 왼쪽에 있으면 삼각형의 법선과 벡터 C의 내적값은 양수입니다(C는 A와 B의 외적의 결과입니다. 이 시나리오에서 A = (V1 - V0) 및 B = (P - V0)). 그러나 P가 A의 오른쪽에 있으면 (그림 4의 V2'와 마찬가지로) 이 내적은 음수입니다. 그림 5에서 볼 수 있습니다. 점 P는 A의 왼쪽에 있을 때 삼각형 안에 있습니다. 방금 설명한 기술을 광선-삼각형 교차 문제에 적용하려면 삼각형의 각 모서리에 대해 왼쪽 / 오른쪽 테스트를 반복해야합니다. 삼각형의 각 모서리에 대해 점 P가 벡터 C의 왼쪽에 있음을 발견하면 (여기서 C는 삼각형의 각 모서리인 V1-V0, V2-V1 및 V0-V2로 정의 됨) P가 삼각형 안에 있는지 알 수 있습니다. 삼각형 모서리 중 하나에 대해 검정이 실패하면 P는 삼각형 경계 밖에 있습니다. 이 프로세스는 그림 6에 나와 있습니다. 삼각형의 각 모서리에 대해 점 P가 벡터 C의 왼쪽에 있음을 발견하면 (여기서 C는 삼각형의 각 모서리에 대해 각각 V1-V0, V2-V1 및 V0-V2로 정의 됨) 다음을 알 수 있습니다. P가 삼각형 안에 있는지 확인하십시오. 삼각형 모서리 중 하나에 대해 검정이 실패하면 P는 삼각형 경계 밖에 있습니다. 이 프로세스는 그림 6에 나와 있습니다. 삼각형의 각 모서리에 대해 점 P가 벡터 C의 왼쪽에 있음을 발견하면 (여기서 C는 삼각형의 각 모서리에 대해 각각 V1-V0, V2-V1 및 V0-V2로 정의 됨) 다음을 알 수 있습니다. P가 삼각형 안에 있는지 확인하십시오. 삼각형 모서리 중 하나에 대해 검정이 실패하면 P는 삼각형 경계 밖에 있습니다. 이 프로세스는 그림 6에 나와 있습니다.

![그림 6 : P가 삼각형 내부에 있는지 확인하기 위해 가장자리를 따라 벡터의 내적과 테스트 된 가장자리의 첫 번째 정점에 의해 정의 된 벡터와 P가 양수인지 테스트 할 수 있습니다 (즉, P는 왼쪽에 있음을 의미). 모서리). P가 세 모서리 모두의 왼쪽에 있으면 P는 삼각형 안에 있습니다.](https://www.scratchapixel.com/images/upload/ray-triangle/triinsideout3.png?)

다음은 pseudocode 에서 내부-외부 테스트의 예입니다.
```cpp
Vec3f edge0 = v1 - v0; 
Vec3f edge1 = v2 - v1; 
Vec3f edge2 = v0 - v2; 
Vec3f C0 = P - v0; 
Vec3f C1 = P - v1; 
Vec3f C2 = P - v2; 
if (dotProduct(N, crossProduct(edge0, C0)) > 0 && 
    dotProduct(N, crossProduct(edge1, C1)) > 0 && 
    dotProduct(N, crossProduct(edge2, C2)) > 0) return true; // P is inside the triangle
```

완전한 광선-삼각형 교차 테스트 루틴의 코드를 작성해 봅시다. 먼저 삼각형의 법선을 계산한 다음 광선과 삼각형이 평행한지 테스트합니다. 만약 광선과 삼각형이 평행하다면 교차 테스트가 실패합니다. 평행이 아닌 경우 t를 계산하여 여기에서 교차점 P의 좌표를 구할 수 있습니다. 내부-외부 테스트(P가 삼각형 모서리의 왼쪽에 있는지 테스트)가 성공하면 광선은 삼각형을 교차하고 P는 삼각형의 경계 안에 있습니다. 이렇다면 테스트에 성공한 것입니다.

```cpp
bool rayTriangleIntersect( 
    const Vec3f &orig, const Vec3f &dir, 
    const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, 
    float &t) 
{ 
    // compute plane's normal
    Vec3f v0v1 = v1 - v0; 
    Vec3f v0v2 = v2 - v0; 
    // no need to normalize
    Vec3f N = v0v1.crossProduct(v0v2); // N 
    float area2 = N.length(); 
 
    // Step 1: finding P
 
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dotProduct(dir); 
    if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
        return false; // they are parallel so they don't intersect ! 
 
    // compute d parameter using equation 2
    float d = N.dotProduct(v0); 
 
    // compute t (equation 3)
    t = (N.dotProduct(orig) + d) / NdotRayDirection; 
    // check if the triangle is in behind the ray
    if (t < 0) return false; // the triangle is behind 
 
    // compute the intersection point using equation 1
    Vec3f P = orig + t * dir; 
 
    // Step 2: inside-outside test
    Vec3f C; // vector perpendicular to triangle's plane 
 
    // edge 0
    Vec3f edge0 = v1 - v0; 
    Vec3f vp0 = P - v0; 
    C = edge0.crossProduct(vp0); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side 
 
    // edge 1
    Vec3f edge1 = v2 - v1; 
    Vec3f vp1 = P - v1; 
    C = edge1.crossProduct(vp1); 
    if (N.dotProduct(C) < 0)  return false; // P is on the right side 
 
    // edge 2
    Vec3f edge2 = v0 - v2; 
    Vec3f vp2 = P - v2; 
    C = edge2.crossProduct(vp2); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side; 
 
    return true; // this ray hits the triangle 
} 
```

## What's Next?

이 장에서는 간단한 기하학을 사용하여 광선-삼각 교차 테스트를 계산하는 기술을 제시했습니다. 그러나 우리가 아직 고려하지 않은, 광선이 앞쪽에서 삼각형에 닿는지 뒤쪽에서 닿는지 여부와 같이, 광선-삼각 교차 테스트에는 훨씬 더 많은 것들이 있습니다. 무게 중심 좌표라고 부르는 것을 계산할 수도 있습니다. 이 좌표는 삼각형에 텍스처를 적용하는 것과 같은 작업을 수행하는 데 필요합니다.