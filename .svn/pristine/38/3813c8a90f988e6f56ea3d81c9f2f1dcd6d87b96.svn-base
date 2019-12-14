<?php
include_once 'blade/view.sendRepair.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="container">
    <!--Heading-->
    <div class="col-md-8 col-md-offset-2">
        <div class="panel myPanel">
            <div class="panel-heading myHeading">
                <strong&nbsp;Lend Asset</strong>
            </div>
            <div class="panel-body">

                <form method="post" class="form-horizontal">
                    <!--            Serial No-->
                    <div class="form-group">
                        <label for="serialNo" class="control-label col-md-3">Serial No :</label>
                        <div class=" col-md-7">
                            <input type="text" name="serialNo" id="serialNo" class="form-control" onblur="checkSerialJS();" placeholder="Serial No" value="<?php
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

                    <!--            User Id-->
                    <div class="form-group">
                        <label for="userId" class="control-label col-md-3">User E-Mail :</label>
                        <div class=" col-md-7">
                            <input type="text" name="userId" id="userId" class="form-control" placeholder="Repaired From" value="<?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairRepairedFrom();
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--            Lending Date-->
                    <div class="form-group">
                        <label for="lendingDate" class="control-label col-md-3">Lending Date :</label>
                        <div class=" col-md-7">
                            <input type="date" name="lendingDate" id="lendingDate" class="form-control" value="<?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairSendingDate();
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--Button-->
                    <div class="form-group">
                        <?php
                        if (!isset($_GET['edit'])){
                            ?>
                            <input type="submit" id="btnLend" class="btn btn-primary col-md-2 col-md-offset-5" name="lend" value="Lend">
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



<script>
    function checkSerialJS() {
        var serial=$('#serialNo').val();
        $.ajax({
            url:"./modules/assetArchive/ui/checkLendSerial.inc",
            type:"get",
            data:{val:serial},
            success:function (data) {
                $('#spnSerialNo').text(data);
                if(data==""){
                    $('#btnLend').prop('disabled',false);
                    $('#btnUpdate').prop('disabled',false);
                }else{
                    $('#btnLend').prop('disabled',true);
                    $('#btnUpdate').prop('disabled',true);
                }
            },
            error:function (data) {

            }
        });
    }
</script>
