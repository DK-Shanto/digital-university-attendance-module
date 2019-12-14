<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'bao/class.assetBao.inc';
include_once MODULES_ASSET.'bao/class.receiveRepairBao.inc';
include_once MODULES_ASSET.'bao/class.sendRepairBao.inc';

$_ReceiveRepairBao=new ReceiveRepairBao();
$_SendRepairBao=new SendRepairBao();
$_AssetBao=new AssetBao();
$_DB=DBUtil::getInstance();

if (isset($_POST['receive'])){
    $RepairDetail=$_ReceiveRepairBao->getRepairByAssetSerialNo($_POST['serialNo'])->getResultObject();
    $Asset=$_SendRepairBao->getAssetIdBySerialNo($_POST['serialNo'])->getResultObject();
    $Repair=new Repair();
    $Repair->setRepairId($_DB->secureInput($RepairDetail->getRepairId()));
    $Repair->setRepairAssetId($Asset->getAssetId());
    $Repair->setRepairReceivingDate($_DB->secureInput($_POST['receivingDate']));
    $Repair->setRepairStatus($_DB->secureInput($_POST['status']));
    $Repair->setRepairReceivedBy($_DB->secureInput($_SESSION['globalUser']->getID()));
    if (!empty($_POST['cost'])){
        $Repair->setRepairCost($_DB->secureInput($_POST['cost']));
    }else{
        $Repair->setRepairCost($_DB->secureInput(0));
    }
    $Repair->setRepairIsReceived($_DB->secureInput(1));

    $_ReceiveRepairBao->receiveRepair($Repair);
}

if (isset($_GET['edit'])){
    $getRow=$_ReceiveRepairBao->getRepairById($_GET['edit'])->getResultObject();
}

if (isset($_POST['update'])){
    $RepairDetail=$_ReceiveRepairBao->getRepairByAssetSerialNo($_POST['serialNo'])->getResultObject();
    $Asset=$_SendRepairBao->getAssetIdBySerialNo($_POST['serialNo'])->getResultObject();

    $Repair=new Repair();
    $Repair->setRepairId($_GET['edit']);
    $Repair->setRepairAssetId($Asset->getAssetId());
    $Repair->setRepairReceivingDate($_DB->secureInput($_POST['receivingDate']));
    $Repair->setRepairStatus($_DB->secureInput($_POST['status']));
    $Repair->setRepairReceivedBy($_DB->secureInput($_SESSION['globalUser']->getID()));
    if (!empty($_POST['cost'])){
        $Repair->setRepairCost($_DB->secureInput($_POST['cost']));
    }else{
        $Repair->setRepairCost($_DB->secureInput(0));
    }
    $Repair->setRepairIsReceived($_DB->secureInput(1));

    $_ReceiveRepairBao->updateRepair($Repair);

    header("Location:".PageUtil::$ASSET_REPAIR_RECEIVE);
}

if (isset($_GET['del'])){
    $_ReceiveRepairBao->deleteRepair($_GET['del']);

    header("Location:".PageUtil::$ASSET_REPAIR_RECEIVE);
}

?>