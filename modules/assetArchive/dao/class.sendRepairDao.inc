<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class SendRepairDao
{

    private $_DB;
    private $_Asset;
    private $_Repair;

    function __construct()
    {
        $this->_DB = DBUtil::getInstance();
        $this->_Asset=new Asset();
        $this->_Repair=new Repair();
    }

    public function getAssetIdBySerialNo($Asset){
        $SQL="SELECT * FROM ams_asset WHERE ams_asset.serialNo='".$Asset."'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();
        $this->_Asset=new Asset();
        $this->_Asset->setAssetId($row['id']);
        $this->_Asset->setAssetWarrantyLimit($row['warrantyLimit']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Asset);

        return $Result;
    }

    public function sendRepair($Repair){
        $ID=$Repair->getRepairId();
        $AssetId=$Repair->getRepairAssetId();
        $Problem=$Repair->getRepairProblem();
        $SendingDate=$Repair->getRepairSendingDate();
        $SentBy=$Repair->getRepairSentBy();
        $RepairedFrom=$Repair->getRepairRepairedFrom();
        $OnWarranty=$Repair->getRepairOnWarranty();

        $SQL="INSERT INTO ams_repair(id,asset_id,problem,sendingDate,sent_by,repaired_from,onWarranty) VALUES ('$ID','$AssetId','$Problem',
             '$SendingDate','$SentBy','$RepairedFrom','$OnWarranty')";

        $SQL=$this->_DB->doQuery($SQL);

        $SQL2="UPDATE ams_asset SET ams_asset.status='On Repair' WHERE ams_asset.id='$AssetId'";
        $SQL2=$this->_DB->doQuery($SQL2);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL*$SQL2);

        return $Result;
    }

    public function getAllRepair(){
        $RepairList=array();

        $SQL="SELECT * FROM ams_repair WHERE ams_repair.isReceived=0 ORDER BY ams_repair.sendingDate";
        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Repair=new Repair();
            $this->_Repair->setRepairId($row['id']);
            $this->_Repair->setRepairAssetId($row['asset_id']);
            $this->_Repair->setRepairProblem($row['problem']);
            $this->_Repair->setRepairSendingDate($row['sendingDate']);
            $this->_Repair->setRepairSentBy($row['sent_by']);
            $this->_Repair->setRepairRepairedFrom($row['repaired_from']);
            $this->_Repair->setRepairOnWarranty($row['onWarranty']);

            $RepairList[]=$this->_Repair;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($RepairList);

        return $Result;
    }

    public function getRepairById($Repair){
        $SQL="SELECT * FROM ams_repair WHERE ams_repair.id='$Repair'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();

        $this->_Repair=new Repair();
        $this->_Repair->setRepairId($row['id']);
        $this->_Repair->setRepairAssetId($row['asset_id']);
        $this->_Repair->setRepairProblem($row['problem']);
        $this->_Repair->setRepairSendingDate($row['sendingDate']);
        $this->_Repair->setRepairSentBy($row['sent_by']);
        $this->_Repair->setRepairRepairedFrom($row['repaired_from']);
        $this->_Repair->setRepairOnWarranty($row['onWarranty']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Repair);

        return $Result;
    }

    public function updateRepair($Repair){
        $SQL="UPDATE ams_repair SET ams_repair.asset_id='".$Repair->getRepairAssetId()."',ams_repair.problem='".$Repair->getRepairProblem()."',
        ams_repair.sendingDate='".$Repair->getRepairSendingDate()."',ams_repair.sent_by='".$Repair->getRepairSentBy()."',
        ams_repair.repaired_from='".$Repair->getRepairRepairedFrom()."',ams_repair.onWarranty='".$Repair->getRepairOnWarranty()."' WHERE ams_repair.id='".$Repair->getRepairId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $SQL2="UPDATE ams_asset SET ams_asset.status='On Repair' WHERE ams_asset.id='".$Repair->getRepairAssetId()."'";
        $SQL2=$this->_DB->doQuery($SQL2);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL*$SQL2);

        return $Result;
    }

    public function deleteRepair($Repair){
        $SQL="DELETE FROM ams_repair WHERE ams_repair.id='$Repair'";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }
}