<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment.blade.inc';
?>
<div class="aa">
Sorry you dont have enough balance to pay fee. Your current account balance is <?php echo $getAccount->getAmount();?> taka.
</div>    
