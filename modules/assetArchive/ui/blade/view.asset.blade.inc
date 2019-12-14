<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'bao/class.assetBao.inc';

$_AssetBao=new AssetBao();
$_DB=DBUtil::getInstance();

if (isset($_POST['addAsset'])){
    $Asset=new Asset();
    $Asset->setAssetId(Util::getGUID());
    $Asset->setAssetTypeId($_DB->secureInput($_POST['typeDDL']));
    $Asset->setAssetSerialNo($_DB->secureInput($_POST['serialNo']));
    $Asset->setAssetModelNo($_DB->secureInput($_POST['modelNo']));
    $Asset->setAssetBrand($_DB->secureInput($_POST['brand']));
    $Asset->setAssetPurchaseDate($_DB->secureInput($_POST['purchaseDate']));
    $Asset->setAssetStatus($_DB->secureInput($_POST['status']));
    $Asset->setAssetConfiguration($_DB->secureInput($_POST['configuration']));
    $Asset->setAssetStuffId($_DB->secureInput($_SESSION['globalUser']->getID()));
    $Asset->setAssetPurchasedFrom($_DB->secureInput($_POST['purchasedFrom']));
    $Asset->setAssetCost($_DB->secureInput($_POST['cost']));
    $Asset->setAssetWarrantyLimit($_DB->secureInput($_POST['warranty']));

    $_AssetBao->createAsset($Asset);
}

if (isset($_GET['edit'])){
    $Asset=new Asset();
    $Asset->setAssetId($_GET['edit']);

    $getRow=$_AssetBao->getAssetById($Asset)->getResultObject();
}

if (isset($_POST['update'])){
    $Asset=new Asset();
    $Asset->setAssetId($_GET['edit']);
    $Asset->setAssetTypeId($_DB->secureInput($_POST['typeDDL']));
    $Asset->setAssetSerialNo($_DB->secureInput($_POST['serialNo']));
    $Asset->setAssetModelNo($_DB->secureInput($_POST['modelNo']));
    $Asset->setAssetBrand($_DB->secureInput($_POST['brand']));
    $Asset->setAssetPurchaseDate($_DB->secureInput($_POST['purchaseDate']));
    $Asset->setAssetStatus($_DB->secureInput($_POST['status']));
    $Asset->setAssetConfiguration($_DB->secureInput($_POST['configuration']));
    $Asset->setAssetStuffId($_DB->secureInput($_SESSION['globalUser']->getID()));
    $Asset->setAssetPurchasedFrom($_DB->secureInput($_POST['purchasedFrom']));
    $Asset->setAssetCost($_DB->secureInput($_POST['cost']));
    $Asset->setAssetWarrantyLimit($_DB->secureInput($_POST['warranty']));

    $_AssetBao->updateAsset($Asset);

    header("Location:".PageUtil::$ASSET);
}

if (isset($_GET['del'])){
    $Asset=new Asset();
    $Asset->setAssetId(($_GET['del']));

    $_AssetBao->deleteAsset($Asset);

    header("Location:".PageUtil::$ASSET);
}

?>