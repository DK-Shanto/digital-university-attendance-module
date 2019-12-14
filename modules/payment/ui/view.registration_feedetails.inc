<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment_details.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Registration Fee </div>
<div class="panel-body">
<h1 class="hh1"> KHULNA UNIVERSITY </h1>
<h2 class="hh1" id="hh2"> Students Payment Receipt </h2>
<div class="aa">
Name: <?php echo $getRegistrationFee->getName(); ?>			<br>
Discipline: <?php echo $getRegistrationFee->getDiscipline(); ?><br>
Term: <?php echo $getRegistrationFee->getTerm(); ?><br>
Student id: <?php echo $getRegistrationFee->getUniversityID(); ?><br>
Date: <?php echo $getRegistrationFee->getDate(); ?><br>
</div> 
<table width="437" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  <tr>
    <td>01. Admission fee</td>
    <td>
	<?php echo $getRegistrationFee->getAdmissionFee();?><br>
    </td>
  </tr>

	<tr>
		<td>02. Pay/Pay book</td>
		<td>
			<?php echo $getRegistrationFee->getPayBook(); ?><br>
		</td>
	</tr>

	<tr>
		<td>03. Security(General)</td>
		<td>
			<?php echo $getRegistrationFee->getSecurity(); ?><br>
		</td>
	</tr>

	<tr>
		<td>04. Transportation</td>
		<td>
			<?php echo $getRegistrationFee->getTransportation(); ?><br>
		</td>
	</tr>

	<tr>
		<td>05. Course registration</td>
		<td>
			<?php echo $getRegistrationFee->getCourseRegistration(); ?><br>
		</td>
	</tr>

	<tr>
		<td>06. Verification/Attestation fee</td>
		<td>
			<?php echo $getRegistrationFee->getVerification(); ?><br>
		</td>
	</tr>

	<tr>
		<td>07. Retake</td>
		<td>
			<?php echo $getRegistrationFee->getRetake(); ?><br>
		</td>
	</tr>

	<tr>
		<td>08. Re-retake</td>
		<td>
			<?php echo $getRegistrationFee->getReRetake(); ?><br>
		</td>
	</tr>

	<tr>
		<td>09. BNCC</td>
		<td>
			<?php echo $getRegistrationFee->getBncc(); ?><br>
		</td>
	</tr>

	<tr>
		<td>10. Library</td>
		<td>
			<?php echo $getRegistrationFee->getLibrary(); ?><br>
		</td>
	</tr>

	<tr>
		<td>11. Medical/Healthcard</td>
		<td>
			<?php echo $getRegistrationFee->getMedical(); ?><br>
		</td>
	</tr>

	<tr>
		<td>12. Cultural</td>
		<td>
			<?php echo $getRegistrationFee->getCultural(); ?><br>
		</td>
	</tr>

	<tr>
		<td>13. Religious fee</td>
		<td>
			<?php echo $getRegistrationFee->getReligiousFee(); ?><br>
		</td>
	</tr>

	<tr>
		<td>14. Examination fee</td>
		<td>
			<?php echo $getRegistrationFee->getExaminationFee(); ?><br>
		</td>
	</tr>

	<tr>
		<td>15. Session Charge</td>
		<td>
			<?php echo $getRegistrationFee->getSessionCharge(); ?><br>
		</td>
	</tr>

	<tr>
		<td>16. Gradesheet</td>
		<td>
			<?php echo $getRegistrationFee->getGradesheet(); ?><br>
		</td>
	</tr>
	<tr>
		<td>17. Provisional Certificate</td>
		<td>
			<?php echo $getRegistrationFee->getProvisionalCertificate(); ?><br>
		</td>
	</tr>

	<tr>
		<td>18. Main Certificate</td>
		<td>
			<?php echo $getRegistrationFee->getMainCertificate(); ?><br>
		</td>
	</tr>

	<tr>
		<td>19. Transcript</td>
		<td>
			<?php echo $getRegistrationFee->getTranscript(); ?><br>
		</td>
	</tr>

	<tr>
		<td>20. Security(Library)</td>
		<td>
			<?php echo $getRegistrationFee->getSecurityLibrary(); ?><br>
		</td>
	</tr>

	<tr>
		<td>21. Equivalence Certificate</td>
		<td>
			<?php echo $getRegistrationFee->getEquivalenceCertificate(); ?><br>
		</td>
	</tr>

	<tr>
		<td>22. Fine(Library)</td>
		<td>
			<?php echo $getRegistrationFee->getFineLibrary(); ?><br>
		</td>
	</tr>

	<tr>
		<td>23. Fine(Course registration)</td>
		<td>
			<?php echo $getRegistrationFee->getFineRegistration(); ?><br>
		</td>
	</tr>

	<tr>
		<td>24. MC/MI Certificate</td>
		<td>
			<?php echo $getRegistrationFee->getMc_Mi(); ?><br>
		</td>
	</tr>

	<tr>
		<td>25. MFIL/PHD</td>
		<td>
			<?php echo $getRegistrationFee->getMphilPhd(); ?><br>
		</td>
	</tr>

	<tr>
		<td>26. Student Welfare</td>
		<td>
			<?php echo $getRegistrationFee->getStudentWelfare(); ?><br>
		</td>
	</tr>

	<tr>
		<td>27. Sports</td>
		<td>
			<?php echo $getRegistrationFee->getSports(); ?><br>
		</td>
	</tr>

	<tr>
		<td>28. Publication</td>
		<td>
			<?php echo $getRegistrationFee->getPublication(); ?><br>
		</td>
	</tr>

	<tr>
		<td>29. Others</td>
		<td>
			<?php echo $getRegistrationFee->getOthers(); ?><br>
		</td>
	<tr>
		<td> Total</td>
		<td>
			<?php echo $getRegistrationFee->getTotal(); ?> <br>
		</td>
	</tr>
	</tr>
</table>