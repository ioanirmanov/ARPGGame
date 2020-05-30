#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "DynamicSprite.generated.h"

UCLASS(Blueprintable)
class ARPG_API UDynamicSprite : public UPaperSprite
{
	GENERATED_BODY()
public:
	UDynamicSprite(const FObjectInitializer& ObjectInitializer);
	void SetTexture(UTexture2D* Texture);

};
