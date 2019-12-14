<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'bao/class.assetBao.inc';
include_once MODULES_ASSET.'bao/class.sendRepairBao.inc';

$_SendRepairBao=new SendRepairBao();
$_AssetBao=new AssetBao();
$_DB=DBUtil::getInstance();

if (isset($_POST['send'])){
    $Asset=$_SendRepairBao->getAssetIdBySerialNo($_POST['serialNo'])->getResultObject();
    $limit=$Asset->getAssetWarrantyLimit();
    $currentDate = new DateTime($_POST['sendingDate']);
    $expireDate = new DateTime($limit);
    $validity = date_diff($currentDate,$expireDate);

    $Repair=new Repair();
    $Repair->setRepairId(Util::getGUID());
    $Repair->setRepairAssetId($Asset->getAssetId());
    $Repair->setRepairProblem($_DB->secureInput($_POST['problem']));
    $Repair->setRepairSendingDate($_DB->secureInput($_POST['sendingDate']));
    $Repair->setRepairSentBy($_DB->secureInput($_SESSION['globalUser']->getID()));
    $Repair->setRepairRepairedFrom($_DB->secureInput($_POST['repairedFrom']));
    if ($validity->format("%R%a") > -1){
        $Repair->setRepairOnWarranty($_DB->secureInput(1));
    }else{
        $Repair->setRepairOnWarranty($_DB->secureInput(0));
    }
    $_SendRepairBao->sendRepair($Repair);
}

if (isset($_GET['edit'])){
    $getRow=$_SendRepairBao->getRepairById($_GET['edit'])->getResultObject();
}

if (isset($_POST['update'])){
    $Asset=$_SendRepairBao->getAssetIdBySerialNo($_POST['serialNo'])->getResultObject();
    $limit=$Asset->getAssetWarrantyLimit();
    $currentDate = new DateTime($_POST['sendingDate']);
    $expireDate = new DateTime($limit);
    $validity = date_diff($currentDate,$expireDate);

    $Repair=new Repair();
    $Repair->setRepairId($_GET['edit']);
    $Repair->setRepairAssetId($Asset->getAssetId());
    $Repair->setRepairProblem($_DB->secureInput($_POST['problem']));
    $Repair->setRepairSendingDate($_DB->secureInput($_POST['sendingDate']));
    $Repair->setRepairSentBy($_DB->secureInput($_SESSION['globalUser']->getID()));
    $Repair->setRepairRepairedFrom($_DB->secureInput($_POST['repairedFrom']));
    if ($validity->format("%R%a") > -1){
        $Repair->setRepairOnWarranty($_DB->secureInput(1));
    }else{
        $Repair->setRepairOnWarranty($_DB->secureInput(0));
    }
    $_SendRepairBao->updateRepair($Repair);

    header("Location:".PageUtil::$ASSET_REPAIR_SEND);
}

if (isset($_GET['del'])){
    $_SendRepairBao->deleteRepair($_GET['del']);

    header("Location:".PageUtil::$ASSET_REPAIR_SEND);
}
?>