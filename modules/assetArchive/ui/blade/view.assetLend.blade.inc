<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'bao/class.assetLendBao.inc';
include_once MODULES_ASSET.'bao/class.sendRepairBao.inc';

$_DB=DBUtil::getInstance();
$_AssetLendBao=new AssetLendBao();
$_SendRepairBao=new SendRepairBao();

if (isset($_POST['lend'])){
    $Asset=$_SendRepairBao->getAssetIdBySerialNo($_POST['serialNo'])->getResultObject();

    $UserAsset=new UserAsset();
    $UserAsset->setUserAssetId(Util::getGUID());
    $UserAsset->setUserAssetUserId($_DB->secureInput($_POST['userId']));
    $UserAsset->setUserAssetAssetId($Asset->getAssetId());
    $UserAsset->setUserAssetLendingDate($_DB->secureInput($_POST['lendingDate']));

    $_AssetLendBao->lendAsset($UserAsset);
}