<?php
include_once 'blade/view.receiveRepair.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="container">
    <!--Heading-->
    <div class="col-md-8 col-md-offset-2">
        <div class="panel myPanel">
            <div class="panel-heading myHeading">
                <strong>&nbsp;Receive Repaired Asset</strong>
            </div>
            <div class="panel-body">

                <form method="post" class="form-horizontal">

                    <!--            Serial No-->
                    <div class="form-group">
                        <label for="serialNo" class="control-label col-md-3">Serial No :</label>
                        <div class=" col-md-7">
                            <input type="text" name="serialNo" id="serialNo" class="form-control" onblur="checkReceiveSerialJS();" placeholder="Serial No" value="<?php
                            if (isset($_GET['edit'])){
                                $Asset=new Asset();
                                $Asset->setAssetId($getRow->getRepairAssetId());
                                $AssetDetail=$_AssetBao->getAssetById($Asset)->getResultObject();
                                echo $AssetDetail->getAssetSerialNo();
                            }
                            ?>" required>
                            <span id="spnSerialNo" class="text-danger"></span>
                        </div>
                    </div>

                    <!--            Receiving Date-->
                    <div class="form-group">
                        <label for="receivingDate" class="control-label col-md-3">Receiving Date :</label>
                        <div class=" col-md-7">
                            <input type="date" name="receivingDate" id="receivingDate" class="form-control" value="<?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairReceivingDate();
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--Repair Status-->
                    <div class="form-group">
                        <label for="status" class="control-label col-md-3">Repair Status :</label>
                        <div class=" col-md-7">
                            <select name="status" id="status" class="form-control" required>
                                <option value="" selected="selected" disabled="disabled">Select Status</option>
                                <option value="Repaired" class="text-success" <?php
                                if (isset($_GET['edit'])){
                                    if ($getRow->getRepairStatus()=="Repaired"){
                                        echo 'selected="selected"';
                                    }
                                }
                                ?>>Repaired</option>
                                <option value="Partially Repaired" class="text-warning" <?php
                                if (isset($_GET['edit'])){
                                    if ($getRow->getRepairStatus()=="Partially Repaired"){
                                        echo 'selected="selected"';
                                    }
                                }
                                ?>>Partially Repaired</option>
                                <option value="Not Repaired" class="text-danger" <?php
                                if (isset($_GET['edit'])){
                                    if ($getRow->getRepairStatus()=="Not Repaired"){
                                        echo 'selected="selected"';
                                    }
                                }
                                ?>>Not Repaired</option>
                            </select>
                        </div>
                    </div>

                    <!--           Cost-->
                    <div class="form-group" id="divCost" <?php if (isset($_GET['edit'])){
                        if ($getRow->getRepairOnWarranty()==1){
                            ?>
                            style="display: none"
                            <?php
                        }
                    } ?>>
                        <label for="cost" class="control-label col-md-3">Cost :</label>
                        <div class=" col-md-7">
                            <input type="number" name="cost" id="cost" class="form-control" placeholder="Cost" <?php
                            if (isset($_GET['edit'])){
                                if ($getRow->getRepairOnWarranty()==0){
                                    ?>
                                    value="<?php echo $getRow->getRepairCost(); ?>" required
                                   <?php
                                }
                            }else{
                                ?>
                                required
                                    <?php
                            }
                            ?>>
                        </div>
                    </div>

                    <!--Button-->
                    <div class="form-group">
                        <?php
                        if (!isset($_GET['edit'])){
                            ?>
                            <input type="submit" id="btnReceive" class="btn btn-primary col-md-2 col-md-offset-5" name="receive" value="Receive">
                            <?php
                        }else{
                            ?>
                            <input type="submit" id="btnUpdate" class="btn btn-primary col-md-2 col-md-offset-5" name="update" value="Update">
                            <?php
                        }
                        ?>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>

<div class="col-md-12" style="margin-top: -12vh">
    <hr>
</div>
<div class="col-md-12" style="margin-top: -3vh">
    <div class="panel panel-table">
        <table class="table table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>Type</th>
                <th>Serial No</th>
                <th>Model No</th>
                <th>Brand</th>
                <th>Problem</th>
                <th>Sent By</th>
                <th>Received By</th>
                <th>Sending Date</th>
                <th>Receiving Date</th>
                <th>Repair Status</th>
                <th>Repaired From</th>
                <th>Cost</th>
                <th>On Warranty</th>
                <th>Edit</th>
                <th>Delete</th>
            </tr>

            <!--Table Cells-->
            <?php
            $Result=$_ReceiveRepairBao->getAllRepair();
            if($Result->getIsSuccess()) {
                $RepairList = $Result->getResultObject();
                foreach ($RepairList as $repair) {
                    $Asset=new Asset();
                    $Asset->setAssetId($repair->getRepairAssetId());
                    ?>
                    <tr <?php if ($repair->getRepairStatus()=="Repaired"){
                        echo 'class="table-cell alert-success"';
                    }elseif ($repair->getRepairStatus()=="Partially Repaired"){
                        echo 'class="table-cell alert-warning"';
                    }else{
                        echo 'class="table-cell alert-danger"';
                    }
                    ?>>
                        <td><?php
                            echo $_AssetBao->getTypeById($_AssetBao->getAssetById($Asset)->getResultObject()->getAssetTypeId())->getResultObject()->getAssetTypeName(); ?>
                        </td>
                        <td>
                            <a href="asset_details.php?serialNo=<?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetSerialNo(); ?>" class="table-a">
                                <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetSerialNo(); ?>
                            </a>
                        </td>
                        <td>
                            <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetModelNo(); ?>
                        </td>
                        <td>
                            <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetBrand(); ?>
                        </td>
                        <td><?php if (strlen($repair->getRepairProblem())>50){
                                echo substr($repair->getRepairProblem(),0,50).'...';
                            }else{
                                echo $repair->getRepairProblem();
                            } ?>
                        </td>
                        <?php
                        $StuffName=$_AssetBao->getStuffById($repair->getRepairSentBy())->getResultObject();
                        ?>
                        <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" class="table-a"><?php
                                echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                ?></a>
                        </td>

                        <?php
                        $StuffName=$_AssetBao->getStuffById($repair->getRepairReceivedBy())->getResultObject();
                        ?>
                        <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" class="table-a"><?php
                                echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                ?></a>
                        </td>

                        <td>
                            <?php echo $repair->getRepairSendingDate(); ?>
                        </td>
                        <td>
                            <?php echo $repair->getRepairReceivingDate(); ?>
                        </td>
                        <td>
                            <?php echo $repair->getRepairStatus(); ?>
                        </td>
                        <td>
                            <?php echo $repair->getRepairRepairedFrom(); ?>
                        </td>
                        <td>
                            <?php if ($repair->getRepairOnWarranty()){
                                echo "---";
                            }else{
                                echo $repair->getRepairCost();
                            }
                            ?>
                        </td>
                        <td <?php if ($repair->getRepairOnWarranty()){
                            echo 'class="text-success"';
                        }else{
                            echo 'class="text-danger"';
                        }
                        ?>>
                            <?php if ($repair->getRepairOnWarranty()){
                                echo 'Yes';
                            }else{
                                echo 'No';
                            } ?>
                        </td>
                        <td><a href="?edit=<?php echo $repair->getRepairId(); ?>"
                               onclick="return confirm('sure to edit !!');">edit</a></td>

                        <td><a href="?del=<?php echo $repair->getRepairId(); ?>"
                               class="span-danger"
                               onclick="return confirm('sure to delete !!');">delete</a></td>
                    </tr>
                    <?php
                }
            }
            ?>
        </table>
    </div>
</div>

<script>
    function checkReceiveSerialJS() {
        var serial=$('#serialNo').val();
        $.ajax({
            url:"./modules/assetArchive/ui/checkReceiveSerial.php",
            type:"get",
            data:{val:serial},
            success:function (data) {
                if (data=='1'){
                    $('#divCost').hide();
                    $('#cost').prop('required',false);
                    $('#spnSerialNo').text("");
                    $('#btnReceive').prop('disabled',false);
                    $('#btnUpdate').prop('disabled',false);
                }else if(data=='0'){
                    $('#divCost').show();
                    $('#spnSerialNo').text("");
                    $('#btnReceive').prop('disabled',false);
                    $('#btnUpdate').prop('disabled',false);
                }else{
                    $('#spnSerialNo').text(data);
                    $('#btnReceive').prop('disabled',true);
                    $('#btnUpdate').prop('disabled',true);
                }
            },
            error:function (data) {

            }
        });
    }
</script>
