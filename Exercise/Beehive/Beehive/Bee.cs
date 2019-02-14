using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Beehive {
	class Bee {
		public const double HoneyUnitsConsumedPerMg = .25;

		public double WeightMg {
			get;
			private set;
		}

		public Bee(double weigthMg) {
			WeightMg = weigthMg;
		}

		virtual public double HoneyConsumptionRate() {
			return WeightMg * HoneyUnitsConsumedPerMg;
		}
	}
}
