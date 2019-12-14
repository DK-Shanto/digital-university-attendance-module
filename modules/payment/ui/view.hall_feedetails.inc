<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment_details.blade.inc';
?>
<div class="panel panel-default">
	<div class="panel-heading">Hall Fee </div>
	<div class="panel-body">
		<h1 class="hh1"> KHULNA UNIVERSITY </h1>
		<h2 class="hh1" id="hh2"> Students Hall Payment Receipt </h2>
		<div class="aa">
		Student Name: <?php echo $getHallFee->getName();?>		<br>
		Discipline: <?php echo $getHallFee->getDiscipline();?><br>
		Student id: <?php echo $getHallFee->getUniversityID();?><br>
		Hall Name: <?php echo $getHallFee->getHallName();?> <br>
		Fiscal Year: <?php echo $getHallFee->getFiscalYear();?> <br>
		Date: <?php echo $getHallFee->getDate();?> <br>
		</div>
<table width="425" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  <tr>
    <td>01. Admission</td>
    <td>
    <?php echo $getHallFee->getAdmission();?><br>
    </td>
  </tr>

	<tr>
		<td>02. Institutional</td>
		<td>
			<?php echo $getHallFee->getInstitutional();?><br>
		</td>
	</tr>

	<tr>
		<td>03. Identification Card</td>
		<td>
			<?php echo $getHallFee->getIdentificationCard();?><br>
		</td>
	</tr>

	<tr>
		<td>04. Seat rent</td>
		<td>
			<?php echo $getHallFee->getSeatRent();?><br>
		</td>
	</tr>

	<tr>
		<td>05. Utensil</td>
		<td>
			<?php echo $getHallFee->getUtensil();?><br>
		</td>
	</tr>

	<tr>
		<td>06. Common room</td>
		<td>
			<?php echo $getHallFee->getCommonRoom();?><br>
		</td>
	</tr>

	<tr>
		<td>07. Sports</td>
		<td>
			<?php echo $getHallFee->getSports();?><br>
		</td>
	</tr>

	<tr>
		<td>08. Religious Event</td>
		<td>
			<?php echo $getHallFee->getReligiousEvent();?><br>
		</td>
	</tr>

	<tr>
		<td>09. Security(Returnable)</td>
		<td>
			<?php echo $getHallFee->getSecurityReturnable();?><br>
		</td>
	</tr>

	<tr>
		<td>10. Contingency</td>
		<td>
			<?php echo $getHallFee->getContingency();?><br>
		</td>
	</tr>

	<tr>
		<td>11. Hall anniversary</td>
		<td>
			<?php echo $getHallFee->getHallAnniversary();?><br>
		</td>
	</tr>

	<tr>
		<td>12. Fine</td>
		<td>
			<?php echo $getHallFee->getFine();?><br>
		</td>
	</tr>

	<tr>
		<td>13. Others</td>
		<td>
			<?php echo $getHallFee->getOthers();?><br>
		</td>
	</tr>
	<tr>
		<td>Total</td>
		<td>
			<?php echo $getHallFee->getTotal();?><br>
		</td>
	</tr>
</table>
<br>