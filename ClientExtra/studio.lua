print("hi")

local InsertService = game:GetService("InsertService")
InsertService:SetTrustLevel(0)
InsertService:SetBaseSetsUrl("http://www.roblox.com/Game/Tools/InsertAsset.ashx?nsets=10&type=base")
InsertService:SetUserSetsUrl("http://www.roblox.com/Game/Tools/InsertAsset.ashx?nsets=20&type=user&userid=%d")
InsertService:SetCollectionUrl("http://www.roblox.com/Game/Tools/InsertAsset.ashx?sid=%d")
InsertService:SetAssetUrl("https://assetdelivery.roblox.com/v1/asset/?id=%d")
InsertService:SetAssetVersionUrl("https://assetdelivery.roblox.com/v1/asset/?assetversionid=%d")
InsertService:SetFreeModelUrl("http://www.roblox.com/Game/Tools/InsertAsset.ashx?type=fm&q=%s&pg=%d&rs=%d")
InsertService:SetFreeDecalUrl("http://www.roblox.com/Game/Tools/InsertAsset.ashx?type=fd&q=%s&pg=%d&rs=%d")

maya.AddLocalCoreScript("StarterScript", game:GetService("ScriptContext"))
