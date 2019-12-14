<?php
include_once './common/class.common.inc';
include_once 'blade/view.recharge.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Recharge Log</div>
<div class="panel-body">
<h1 class="hh1"> KHULNA UNIVERSITY </h1>
<h2 class="hh1" id="hh2"> Account Recharge </h2>
<div class="aa">
</div>    
<form class="f1" method="post">
	<div class="aa">
		 Email: 
	<input type="text" name="email" size="20">	<br> <br>
	</div>
	<div class="aa">
		 Amount: 
	<input type="text" name="amount" size="20">	<br> <br>
	</div>
	<input id="btn_s" type="submit" value="Recharge" name="recharge"><br>
	
</form>
<table class="table">
  <tr>
    <th>Date</th>
    <th>Account</th>
    <th>Ammount</th>
  </tr>
  <?php
  foreach ($getRow as $result) {
  ?>
  <tr>
    <td><?php echo $result->getDate();?></td>
    <td><?php echo $result->getEmail();?></td>
    <td><?php echo $result->getAmount();?></td>
  </tr>
<?php } ?>
</table>