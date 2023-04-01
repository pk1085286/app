import UIKit

class TravelBookingViewController: UIViewController {
    
    @IBOutlet weak var destinationTextField: UITextField!
    @IBOutlet weak var dateTextField: UITextField!
    @IBOutlet weak var travelerCountTextField: UITextField!
    @IBOutlet weak var paymentButton: UIButton!
    
    var destination: String?
    var date: Date?
    var travelerCount: Int?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Set up the payment button
        paymentButton.layer.cornerRadius = 5.0
        paymentButton.clipsToBounds = true
        paymentButton.setTitle("Pay Now", for: .normal)
    }
    
    @IBAction func destinationTextFieldDidChange(_ sender: Any) {
        destination = destinationTextField.text
    }
    
    @IBAction func dateTextFieldDidChange(_ sender: Any) {
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "MM/dd/yyyy"
        date = dateFormatter.date(from: dateTextField.text!)
    }
    
    @IBAction func travelerCountTextFieldDidChange(_ sender: Any) {
        travelerCount = Int(travelerCountTextField.text!)
    }
    
    @IBAction func paymentButtonPressed(_ sender: Any) {
        // Process payment using a third-party payment processing API
        // If payment is successful, confirm booking and send email confirmation
        // If payment fails, display error message to user
    }
}
